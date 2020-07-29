// Author: jc5302
// remainder of the floating point division operation
// Rename this file to xllfmod.cpp and implement XLL.FMOD which calls fmod
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

AddInX xai_fmod(
	FunctionX(XLL_DOUBLEX, X_("?xll_fmod"), X_("XLL.FMOD"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is the numerator."))
	.Arg(XLL_DOUBLEX, X_("y"), X_("is the denominator."))
	.FunctionHelp(X_("the remainder of x divided by y"))
	.Category(X_("XLL"))
	.Documentation(LR"(
        The remainder of x divided by y.
    )")
);

double WINAPI xll_fmod(double x, double y)
{
#pragma XLLEXPORT

	return fmod(x, y);
}

#ifdef _DEBUG

xll::test test_xll_fmod([]() {
	double presult;
	double x = 5;
	double y = 2;
	presult = xll_fmod(x, y);
	ensure(presult == 1);
	});

#endif // _DEBUG 