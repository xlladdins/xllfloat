// Author: yz3632
// extracts exponent of the number
// Rename this file to xlllogb.cpp and implement XLL.LOGB which calls logb
// Add documentation and a test function that runs in debug mode.


#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_logb(
	FunctionX(XLL_DOUBLEX, X_("?xll_logb"), X_("XLL.LOGB"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a double number "))
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns the exponent of x"))
	.Documentation(LR"(
        Return the exponent of a number.
    )")
);
double WINAPI
xll_logb(double x)
{
#pragma XLLEXPORT
	double s;
	s = logb(x);
	return s;
}

#ifdef _DEBUG

xll::test test_xll_logb([]() {
	double result;
	double x = 4;
	result = xll_logb(x);
	ensure(result == 2);
	});
#endif