// ulp.cpp - units in the last place
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"
#include "ulp.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

AddInX xai_ulp(
	FunctionX(XLL_DOUBLEX, X_("?xll_ulp"), X_("ULP"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("x"), X_("is a floating point number.")),
		ArgX(XLL_DOUBLEX, X_("y"), X_("is a floating point number."))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("The number of floating point values that can be exactly represented between x and y"))
	.Documentation(
		X_("Note <codeInline>ULP(y, x) = n</codeInline> if and only ")
		X_("if <codeInline>y = NEXTAFTER(x, n)</codeInline>.")
/*		,
		xml::xlink(X_("NEXTAFTER"))
*/	)
);
double WINAPI
xll_ulp(double x, double y)
{    
#pragma XLLEXPORT

	return static_cast<double>(ulp(x, y));
}

#ifdef _DEBUG

template<class T>
void
xll_test_nextafter(void)
{
    T x = T(1.23), y;
		
	y = nextafter(x, x + 1);
	ensure (1 == ulp(y, x));
	y = nextafter(x, x - 1);
	ensure (-1 == ulp(y, x));
}

int
xll_test_ulp(void)
{
	try {
		xll_test_nextafter<float>();
		xll_test_nextafter<double>();
	}
	catch (const std::exception& ex) {
		XLL_ERROR(ex.what());

		return 0;
	}

	return 1;
}

static Auto<OpenAfter> xao_test_ulp(xll_test_ulp);

#endif // _DEBUG