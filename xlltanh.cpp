// Author: ts3157
// hyperbolic tangent
// Rename this file to xlltanh.cpp and implement XLL.TANH which calls tanh
// Add documentation and a test function that runs in debug mode.
// tanh.c - calls corresponding C library function
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"
#include <cmath>
#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_tanh(
	FunctionX(XLL_DOUBLEX, X_("?xll_tanh"), X_("XLL.TANH"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns tanh(x)"))
	.Documentation(LR"(Computes the hyperbolic tangent of x)")
);

double WINAPI
xll_tanh(double x)
{
#pragma XLLEXPORT
	double se(1.0);

	se = tanh(x);
	//se[1] = exp;

	return se;
}

#ifdef _DEBUG
xll::test test_xll_tanh([]() {
	double presult;
	double x = 1;
	presult = xll_tanh(x);
	ensure(presult == std::tanh(1));
	});
#endif