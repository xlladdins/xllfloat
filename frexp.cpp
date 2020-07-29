// frexp.c - calls corresponding C library function
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

AddInX xai_frexp(
	FunctionX(XLL_FPX, X_("?xll_frexp"), X_("FREXP"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("x"), X_("is a floating point number "))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns array {sig, exp} where 0.5 le sig lt 1 and x = sig*2^exp"))
	.Documentation(X_(R"(The inverse of <codeInline>LDEXP</codeInline>.)"))
);
_FP12* WINAPI
xll_frexp(double x)
{
#pragma XLLEXPORT
	static xll::FP12 se(1, 2);
	int exp;

	se[0] = frexp(x, &exp);
	se[1] = exp;

	return se.get();
}
