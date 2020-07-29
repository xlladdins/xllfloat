// polynomial.cpp evaluate a polynomial
#include "xll/xll/xll.h"

using namespace xll;

AddInX xai_polynomial(
    FunctionX(XLL_DOUBLEX, X_("?xll_polynomial"), X_("POLYNOMIAL"))
    .Args({
        ArgX(XLL_FPX, X_("coefficients"), X_("is an array of polynomial coefficients.")),
        ArgX(XLL_DOUBLEX, X_("x"), X_("is the value at which to evaluate the polynomial."))
    })
    .FunctionHelp(X_("Returns c[0] + c[1]*x + c[2]*x^2 + ... where c is the array of coefficients"))
    .Category(X_("XLL"))
    .Documentation(X_(R"(
        Evaluates the polynomial using the Horner method.
    )"))
);
double WINAPI xll_polynomial(const _FPX* pc, double x)
{
#pragma XLLEXPORT
    double result = 0;

    auto n = size(*pc);
    for (int i = 1; i <= n; ++i) {
        result = pc->array[n - i] + x * result; // Horner method
    }

    return result;
}