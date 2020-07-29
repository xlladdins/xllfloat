// !!! move this out of xllfloat
#include <algorithm>
#include "xll/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY X_("ARRAY")
#endif

using namespace xll;

AddInX xai_array_set(
    FunctionX(XLL_HANDLEX, X_("?xll_array_set"), X_("ARRAY.SET"))
    .Args({
        ArgX(XLL_FPX, X_("Array"), X_("is an array of numbers. ")) 
    })
    .Uncalced()
    .Category(CATEGORY)
    .FunctionHelp(X_("Return a handle to an array."))
    .Documentation(X_("The array is stored in memory and can be retrieved using ARRAY.GET."))
);
HANDLEX WINAPI xll_array_set(const _FPX* pa)
{
#pragma XLLEXPORT
    handle<xll::FPX> ha(new xll::FPX(*pa));

    return ha.get();
}

AddInX xai_array_get(
    FunctionX(XLL_FPX, X_("?xll_array_get"), X_("ARRAY.GET"))
    .Args({
        ArgX(XLL_HANDLEX, X_("Handle"), X_("is handle to an array returned by ARRAY.SET."))
    })
    .Category(CATEGORY)
    .FunctionHelp(X_("Return an array from a handle."))
    .Documentation(X_("Retrieve an array created by ARRAY.SET."))
);
_FPX* WINAPI xll_array_get(HANDLEX h)
{
#pragma XLLEXPORT
    try {
        return handle<xll::FPX>(h)->get();
    }
    catch (const std::exception& ex) {
        XLL_ERROR(ex.what());
    }

    return 0;
}

AddInX xai_array_apply(
    FunctionX(XLL_LPOPERX, X_("?xll_array_apply"), X_("ARRAY.APPLY"))
    .Args({
        ArgX(XLL_LPOPERX, X_("f"), X_("is a handle to a user defined function.")),
        ArgX(XLL_LPOPERX, X_("x"), X_("is an array of values for the first argument.")),
        ArgX(XLL_LPOPERX, X_("y"), X_("is an array of values for the second argument."))
    })
    .Category(CATEGORY)
    .FunctionHelp(X_("Return a matrix of values."))
    .Documentation(
        X_("Return a two-dimensional array of f(x,y). ")
        X_("If y is missing then return a one-dimensional array of f(x). ")
    )
);
LPOPERX WINAPI xll_array_apply(const LPOPERX pf, const LPOPERX px, const LPOPERX py)
{
#pragma XLLEXPORT
    static OPERX result;

    try {
        if (py->xltype == xltypeMissing) {
            result.resize(px->size(), 1);

            for (WORD i = 0; i < px->size(); ++i) {
                result[i] = ExcelX(xlUDF, *pf, (*px)[i]);
            }
        }
        else {
            result.resize(px->size(), py->size());

            for (WORD i = 0; i < px->size(); ++i) {
                for (WORD j = 0; j < py->size(); ++j) {
                    result(i, j) = ExcelX(xlUDF, *pf, (*px)[i], (*py)[j]);
                }
            }
        }
    }
    catch (const std::exception& ex) {
        XLL_ERROR(ex.what());

        return 0;
    }

    return &result;
}

AddInX xai_array_interval(
    FunctionX(XLL_FPX, X_("?xll_array_intervaX_("), X_(")ARRAY.INTERVAX_("))
    .Args({
        ArgX(XLL_DOUBLEX, X_(")start"), X_("is the first value of the array.")),
        ArgX(XLL_DOUBLEX, X_("stop"), X_("is the last value of the array.")),
        ArgX(XLL_DOUBLEX, X_("step"), X_("is the step size or count."))
    })
    .Category(X_("ARRAY"))
    .FunctionHelp(X_("Return an interval from start to stop (inclusive)."))
    .Documentation(
        X_("If step is less than 1, use that as the increment. ")
        X_("If step is greater than 1, use that as the count for an array of equally spaced elements. ")
    )
);
_FPX* WINAPI xll_array_interval(double b, double e, double n)
{
#pragma XLLEXPORT
    static xll::FPX result;

    try {
        ensure(b < e);
        ensure(n > 0);

        if (n <= 1) {
            result.resize(static_cast<RW>((e - b) / n) + 1, 1);
            for (WORD i = 0; i < result.size(); ++i)
                result[i] = b + i * n;
        }
        else {
            double dx = (e - b) / (n - 1);
            result.resize(static_cast<RW>(n), 1);
            for (WORD i = 0; i < result.size(); ++i)
                result[i] = b + i*dx;
        }

    }
    catch (const std::exception& ex) {
        XLL_ERROR(ex.what());

        return 0;
    }

    return result.get();
}

AddInX xai_array_slice(
    FunctionX(XLL_FPX, X_("?xll_array_slice"), X_("ARRAY.SLICE"))
    .Args({
        ArgX(XLL_FPX, X_("Array"), X_("is an array for numbers.")),
        ArgX(XLL_WORDX, X_("start"), X_("is the first index into the the array.")),
        ArgX(XLL_WORDX, X_("stride"), X_("is the step increment.")),
        ArgX(XLL_WORDX, X_("count"), X_("is the number of elements to take."))
    })
    .Category(X_("ARRAY"))
    .FunctionHelp(X_("Return a slice of an array."))
    .Documentation(
        X_("Return array elements at start, start + stride, ..., start + (count-1)*stride. ")
        X_("If count is zero then all available elements are taken. ")
    )
);
_FPX* WINAPI xll_array_slice(const _FPX* pa, WORD i, WORD di, WORD n)
{
#pragma XLLEXPORT
    static xll::FPX result;

    try {
        ensure(i < size(*pa));

        if (di == 0)
            di = 1;
        
        if (n == 0)
            n = static_cast<WORD>((size(*pa) - i) / di);
        
        result.resize(n, 1);
        for (WORD j = 0; j < n; ++j)
             result[j] = pa->array[i + j*di];
    }
    catch (const std::exception& ex) {
        XLL_ERROR(ex.what());

        return 0;
    }

    return result.get();
}

AddInX xai_array_sort(
    FunctionX(XLL_FPX, X_("?xll_array_sort"), X_("ARRAY.SORT"))
    .Args({
        ArgX(XLL_FPX, X_("array"), X_("is the array to be sorted.")),
        ArgX(XLL_LONGX, X_("n"), X_("is the number of elements to sort."))
    })
    .Category(CATEGORY)
    .FunctionHelp(X_("Sort an array of numbers."))
    .Documentation(X_(R"(
Sort an array in numeric order. If n is zero then all elements are sorted from high to low. 
If n is -1 all elements are sorted from low to high. Other values of n perform a partial sort
in decending order if n is positive and increasing order if n is negative.
)"))
);
_FPX* WINAPI xll_array_sort(_FPX* pa, LONG n)
{
#pragma XLLEXPORT

    if (n == 0) {
        std::sort(begin(*pa), end(*pa));
    }
    else if (n == -1) {
        std::sort(begin(*pa), end(*pa), std::less<double>{});
    }
    else if (n > 0) {
        std::partial_sort(begin(*pa), pa->array + n, end(*pa));
    }
    else {
        std::partial_sort(begin(*pa), pa->array - n, end(*pa), std::less<double>{});
    }

    return pa;
}

AddInX xai_array_grade(
    FunctionX(XLL_FPX, X_("?xll_array_grade"), X_("ARRAY.GRADE"))
    .Args({
        ArgX(XLL_FPX, X_("array"), X_("is the array to be graded.")),
        ArgX(XLL_LONGX, X_("n"), X_("is the number of elements to grade."))
    })
    .Category(CATEGORY)
    .FunctionHelp(X_("Grade an array of numbers."))
    .Documentation(X_(R"(
Grade an array in numeric order. If n is zero then all elements are graded from high to low. 
If n is -1 all elements are graded from low to high. Other values of n perform a partial grade
in decending order if n is positive and increasing order if n is negative.
The result of INDEX(a, 1 + ARRAY.GRADE(a,n)) is identical to ARRAY.SORT(a,n). 
)"))
);
#pragma warning(push)
#pragma warning(disable: 4244)
_FPX* WINAPI xll_array_grade(const _FPX* pa, LONG n)
{
#pragma XLLEXPORT
    static xll::FPX iota;
    
    iota.resize(pa->rows, pa->columns);

    for (int i = 0; i < iota.size(); ++i)
        iota[i] = i;

    const double* a = pa->array;
    const auto& p = [n, a](int i, int j) { 
        return n >= 0 ? a[i] < a[j] : a[i] > a[j]; 
    };

    if (n == 0 || n == -1) {
        std::sort(iota.begin(), iota.end(), p);
    }
    else {
        std::partial_sort(iota.begin(), iota.begin() + abs(n), iota.end(), p);
    }

    return iota.get();
}
#pragma warning(pop)

#include <random>


// use MKL vector random number generator???

static std::default_random_engine e;

AddInX xai_array_random(
    FunctionX(XLL_FPX, X_("?xll_array_random"), X_("ARRAY.RANDOM"))
    .Args({
        ArgX(XLL_WORDX, X_("Rows"), X_("is the number of rows.")),
        ArgX(XLL_WORDX, X_("Columns"), X_("is the number of columns.")),
        ArgX(XLL_DOUBLEX, X_("_Min"), X_("is the optional lower bound of the random numbers generated. Default is 0.")),
        ArgX(XLL_DOUBLEX, X_("_Max"), X_("is the optional upper bound of the random numbers generated. Default is 1. "))
    })
    .Category(CATEGORY)
    .FunctionHelp(X_("Return a Rows x Columns array of uniformly distributed random numbers between Min and Max."))
    .Documentation(X_("Uses std::default_random_engine and std::uniform_real_distribution."))
);  
_FPX* xll_array_random(WORD r, WORD c, double min, double max)
{
#pragma XLLEXPORT
    static xll::FPX a;

    a.resize(r, c);

    if (max == 0 && min == 0)
        max = 1;

    std::uniform_real_distribution<double> u(min, max);

    for (WORD i = 0; i < a.size(); ++i)
        a[i] = u(e);

    return a.get();
}
