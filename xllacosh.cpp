// Author: ct2966
// computes the inverse hyperbolic cosine (arcosh(x))
// Rename this file to xllacosh.cpp and implement XLL.ACOSH which calls acosh
// Add documentation and a test function that runs in debug mode.



// chgsign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_arcosh(
	FunctionX(XLL_DOUBLEX, X_("?xll_arcosh"), X_("ACOSH"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(X_("computes the inverse hyperbolic cosine (arcosh(x)) by calling acosh()"))
	.Documentation(LR"(
        The _arcosh functions return a value that's the inverse hyperbolic cosine (arcosh(x))
    )")
);
double WINAPI
xll_arcosh(double x)
{
#pragma XLLEXPORT

	return acosh(x);
}


#ifdef _DEBUG


	xll::test test_xll_arcosh([]()
	{

		double input = 1.000;
		double result = xll_arcosh(input);

		ensure(result == 0.0000);
	});

#endif // _DEBUG
