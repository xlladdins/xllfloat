// nextafter.cpp - IEEE recommended functions.
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_nextafter(
	FunctionX(XLL_DOUBLEX, X_("?xll_nextafter"), X_("NEXTAFTER"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("x"), X_("is a floating point number")),
		ArgX(XLL_LONGX, X_("n"), X_("is an integer "))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns the n-th closest representable neighbor of x by calling _nextafter()"))
	.Documentation(
		X_("Note <codeInline>ULP(y, x) = n</codeInline> if and only if <codeInline>y = NEXTAFTER(x, n)</codeInline>.")
/*		, // see also
		xml::xlink("ULP")
*/	)
);
double WINAPI
xll_nextafter(double x, LONG n)
{
#pragma XLLEXPORT

	if (n > 0) {
		while (n--)
			x = _nextafter(x, x + 1);
	}
	else if (n < 0) {
		while (n++)
			x = _nextafter(x, x - 1);
	}

	return x;
}
