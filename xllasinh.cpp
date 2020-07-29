// Author: js5178
// computes the inverse hyperbolic sine (arsinh(x))
// Rename this file to xllasinh.cpp and implement XLL.ASINH which calls asinh
// Add documentation and a test function that runs in debug mode.

#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_asinh(
	FunctionX(XLL_DOUBLEX, X_("?xll_asinh"), X_("XLL.ASINH"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns the area hyperbolic sine of x."))
	.Documentation(LR"(
Computes the area hyperbolic sine for the given floating point input.
    )")
);
double WINAPI
xll_asinh(double x)
{
#pragma XLLEXPORT
	return static_cast<double>(asinh(x));
}

#ifdef _DEBUG

xll::test test_xll_asinh([]() {
	double param, result;
	param = exp(2) - cosh(2);
	result = asinh(param);
	ensure(2.0 == result);
});

#endif // _DEBUG