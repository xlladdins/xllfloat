// reverse.cpp - reverse elements of an array
// !!! move out of xllfloat
#include <algorithm>
#include "xll/xll/xll.h"

using namespace xll;

AddInX xai_reverse(
    FunctionX(XLL_FPX, X_("?xll_reverse"), X_("REVERSE"))
    .Args({
        ArgX(XLL_FPX, X_("array"), X_("is an array of numbers."))
    })
    .FunctionHelp(X_("Reverse an array of numbers."))
    .Category(X_("XLL"))
);
_FPX* WINAPI xll_reverse(_FPX* pa)
{
#pragma XLLEXPORT

    std::reverse(begin(*pa), end(*pa));

    return pa;
}