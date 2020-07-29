// chgsign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

AddInX xai_chgsign(
	FunctionX(XLL_DOUBLEX, X_("?xll_chgsign"), X_("CHGSIGN"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("x"), X_("is a floating point number."))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Reverses the sign of x by calling _chgsign()"))
	.Documentation(X_(R"(
        The _chgsign functions return a value that's equal to the floating-point argument x, 
        but with its sign reversed. There is no error return.
    )"))
);
double WINAPI
xll_chgsign(double x)
{
#pragma XLLEXPORT

	return _chgsign(x);
}
