// ldexp.c - calls corresponding C library function
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_ldexp(
	FunctionX(XLL_DOUBLEX, X_("?xll_ldexp"), X_("LDEXP"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("sig"), X_("is the significand")),
		ArgX(XLL_LONGX, X_("exp"), X_("is the exponent "))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns sig*2^exp using the C library function ldexp()"))
	.Documentation(LR"("This function is the inverse of <codeInline>FREXP</codeInline>.)")
);
double WINAPI
xll_ldexp(double sig, LONG exp)
{
#pragma XLLEXPORT
	double x;

	x = ldexp(sig, exp);

	return x;
}
