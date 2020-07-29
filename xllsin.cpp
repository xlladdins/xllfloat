// Author: rl3107
// computes sine (sin(x))
// Rename this file to xllsin.cpp and implement XLL.SIN which calls sin
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_sin(
	FunctionX(XLL_DOUBLEX, X_("?xll_sin"), X_("XLL.SIN"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating number."))
	.FunctionHelp(X_("Returns sin(x)"))
	.Category(CATEGORY)
	.Documentation(LR"(
        Evaluates the sin(x) using the Horner method.
    )")
);
double WINAPI
xll_sin(double x)
{
#pragma XLLEXPORT

	return sin(x);
}

#ifdef _DEBUG

xll::test test_xll_sin([]() {
	double presult;
	double x = 0;
	presult = xll_sin(x);
	ensure(presult == 0);
	});

#endif // _DEBUG