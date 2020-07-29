// finite.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_finite(
	FunctionX(XLL_BOOLX, X_("?xll_finite"), X_("FINITE"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("x"), X_("is a floating point number "))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Determines whether the given double-precision floating-point value is finite by calling _finite()"))
	.Documentation(X_(R"(
        This function returns TRUE if x is either a normal or subnormal finite value. 
        It returns FALSE if the argument is infinite or a NaN. 
    )"))
);
BOOL WINAPI
xll_finite(double x)
{
#pragma XLLEXPORT

	return TRUE == _finite(x);
}
