// Author: xh2443
// returns e raised to the given power, minus one (ex-1)
// Rename this file to xllexpm1.cpp and implement XLL.EXPM1 which calls expm1
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

AddInX xai_expm1(
	FunctionX(XLL_DOUBLEX, X_("?xll_expm1"), X_("XLL.EXPM1"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is the floating."))
	.Category(CATEGORY)
	.FunctionHelp(X_("Computes e raised to the given power, minus one."))
	.Documentation(X_(R"("Computes e raised to the given power, minus one."
	)")
);
double WINAPI
xll_expm1(double x)
{
#pragma XLLEXPORT

	return exp(x) - 1;
}

#ifdef _DEBUG

xll::test test_xll_expm1([]() {
	double presult;
	double param = 0;
	presult = xll_expm1(param);
	ensure(presult == -1);
	});

#endif // _DEBUG 