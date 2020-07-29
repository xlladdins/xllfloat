// Author: ge2247
// fused multiply-add operation
// Rename this file to xllfma.cpp and implement XLL.FMA which calls fma
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

AddInX xai_fma(
	FunctionX(XLL_DOUBLEX, X_("?xll_fma"), X_("XLL.FMA"))
	.Args({
		ArgX(XLL_DOUBLEX, X_("a"), X_("is the first input.")/*!!!, X_("10")*/),
		ArgX(XLL_DOUBLEX, X_("b"), X_("is the second input.")/*!!!, X_("20")*/),
		ArgX(XLL_DOUBLEX, X_("c"), X_("is the third input.")/*!!!, X_("30")*/)
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Computes the sum of the product of the first and second inputs and the third input.\n\n a*b+c"))
	.Documentation(X_(R"(
Computes the sum of the product of the first and second inputs and the third inputs (Fused Multiply-Add)
Given three inputs a, b, and c, the function computes a * b + c without loss of precision in any intermediate step.
)"))
);

double WINAPI
xll_fma(double a, double b, double c)
{
#pragma XLLEXPORT
	double se(1.0);

	se = fma(a, b, c);

	return se;
}

/*
#ifdef _DEBUG

xll::test test_xll_fma([]() {
	double presult;
	double one = 10;
	double two = 20;
	double three = 30;
	presult = xll_fma(one, two, three);
	ensure(presult == 230);
	});

#endif // _DEBUG
*/