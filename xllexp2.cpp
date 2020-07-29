// Author: yg2707
// returns 2 raised to the given power (2x)
// Rename this file to xllexp2.cpp and implement XLL.EXP2 which calls exp2
// Add documentation and a test function that runs in debug mode.

#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

AddInX xai_exp2(
	FunctionX(XLL_DOUBLEX, X_("?xll_exp2"), X_("XLL.EXP2"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(X_("return exp2(x) by calling _exp2()"))
	.Documentation(LR"(
        The _exp2 functions return a value that's equal to exp2(x). There will be no error return.
    )")
);
double WINAPI
xll_exp2(double x)
{
#pragma XLLEXPORT

	return exp2(x);
}

#ifdef _DEBUG

xll::test test_xll_exp2([]() {

	double presult;
	double x = 4;
	presult = xll_exp2(x);
	ensure(presult == 16);
	});

#endif // _DEBUG