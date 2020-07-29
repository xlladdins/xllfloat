// Author: lz2735
// decomposes a number into integer and fractional parts
// Rename this file to xllmodf.cpp and implement XLL.MODF which calls modf
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;
AddInX xai_modf(
	FunctionX(XLL_FPX, X_("?xll_modf"), X_("XLL.MODF"))
	.Arg(XLL_DOUBLEX, X_("x"), X_("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(X_("Decomposes a number into integer and fractional parts"))
	.Documentation(LR"(
        The _modf functions return an array with two elements that are the integer part of the number and the fractional part of the number. There is no error return.
    )")
);
_FP12* WINAPI
xll_modf(double x)
{
#pragma XLLEXPORT
	double intpart, fractpart;
	static xll::FP12 result(1, 2);
	fractpart = modf(x, &intpart);
	result[0] = intpart;
	result[1] = fractpart;
	return result.get();
}
#ifdef _DEBUG

xll::test test_xll_modf([]() {
	double param = 2.35;
	ensure((xll_modf(param)->array[0] == 2) && (xll_modf(param)->array[1] == 0.35));
	});
#endif 




