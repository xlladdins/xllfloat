// Author: ml4403
// raises a number to the given power (xy)
// Rename this file to xllpow.cpp and implement XLL.POW which calls pow
// Add documentation and a test function that runs in debug mode.
// copysign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

AddInX xai_pow(
	FunctionX(XLL_DOUBLEX, X_("?xll_pow"), X_("XLL.POW"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("the number to be raised"))
	.Arg(XLL_DOUBLEX, X_("y"), X_("The power that it raise to "))
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns x raised to the power of y"))
	.Documentation(LR"(
		The pow function returns the x raised to the power of y
		There is no error return.
        
    )")
);
double WINAPI
xll_pow(double x, double y)
{
#pragma XLLEXPORT

	return pow(x, y);
}

#ifdef _DEBUG
xll::test test_xll_pow([]() {
	double base = 9;
	double power = 2;
	double presult = xll_pow(base, power);
	ensure(presult == 81);
	});

#endif // DEBUG