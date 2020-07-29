// copysign.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_copysign(
	FunctionX(XLL_DOUBLEX, X_("?xll_copysign"), X_("COPYSIGN"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("x"), X_("is a floating point number")),
		ArgX(XLL_DOUBLEX, X_("y"), X_("is a floating point number "))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns x with the sign of y by calling _copysign()"))
	.Documentation(X_(R"(
        The copysign functions return a floating-point value that combines the magnitude of
        <codeInline>x</codeInline> and the sign of <codeInline>y</codeInline>. 
        There is no error return.
        Note <codeInline>x == copysign(x,y)</codeInline> is true if 
        <codeInline>x</codeInline> and <codeInline>y</codeInline> have the same sign.
    )"))
);
double WINAPI
xll_copysign(double x, double y)
{
#pragma XLLEXPORT

	return _copysign(x, y);
}
