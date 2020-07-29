// Author: zf2209
// larger of two floating point values
// Rename this file to xllfmax.cpp and implement XLL.FMAX which calls fmax
// Add documentation and a test function that runs in debug mode.

#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_fmax(
	FunctionX(XLL_DOUBLEX, X_("?xll_fmax"), X_("XLL.FMAX"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating point number"))
	.Arg(XLL_DOUBLEX, X_("y"), X_("is a floating point number"))
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns larger of two floating point values of x and y by calling XLL.FMAX()"))
	.Documentation(LR"(
        The fmax functions return a floating-point value that is the larger between the input floating point values x and y. 
        There is no error return.
    )")
);
double WINAPI
xll_fmax(double x, double y)
{
#pragma XLLEXPORT

	return fmax(x, y);
}

#ifdef _DEBUG

xll::test test_xll_fmax([]() {
	double presult;
	double numer = 0.2;
	double denom = 0.1;
	presult = xll_fmax(numer, denom);
	ensure(presult == 0.2);
	});

#endif // _DEBUG 