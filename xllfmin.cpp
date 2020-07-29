// Author: sf3000
// smaller of two floating point values
// Rename this file to xllfmin.cpp and implement XLL.FMIN which calls fmin
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"
#include <algorithm>

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

AddInX xai_fmin(
	FunctionX(XLL_DOUBLEX, X_("?xll_fmin"), X_("XLL.FMIN"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is the first input floating point value."), X_("1.1"))
	.Arg(XLL_DOUBLEX, X_("y"), X_("is the second input floating point value."), X_("3.22"))
	.Category(CATEGORY)
	.FunctionHelp(X_("Computes the smaller of two floating point values."))
	.Documentation(LR"(
		Returns the smaller of two floating point values.
	)")
);

double WINAPI
xll_fmin(double x, double y)
{
#pragma XLLEXPORT
	return std::min(x, y);
}

#ifdef _DEBUG

xll::test test_xll_fmin([]() {
	double x = 1.1;
	double y = 3.22;
	double result = xll_fmin(x, y);
	ensure(fabs(result - 1.1) <= 1e-6);
	});

#endif // _DEBUG





