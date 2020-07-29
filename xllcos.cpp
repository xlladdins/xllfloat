// Author: yl4419
// computes cosine (cos(x))
// Rename this file to xllcos.cpp and implement XLL.COS which calls cos
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

AddInX xai_cos(
	FunctionX(XLL_DOUBLEX, X_("?xll_cos"), X_("XLL.COS"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(X_("Compute cos(x)"))
	.Documentation(LR"(
        This function calculates the value of cos(x) 
    )")
);

double WINAPI
xll_cos(double x)
{
#pragma XLLEXPORT


	return cos(x);
}

#ifdef _DEBUG

xll::test test_xll_cos([]() {
	double presult;
	double x = 0;
	presult = xll_cos(x);
	ensure(presult == 1);
	});

#endif // _DEBUG
