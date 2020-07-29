// float_bits.cpp - floating point bits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY X_("Float")
#endif

using namespace xll;

static AddInX xai_float_bits(
	FunctionX(XLL_FPX, X_("?xll_float_bits"), X_("FLOAT.BITS"))
	.Args({ 
		ArgX(XLL_DOUBLEX, X_("Num"), X_("is a floating point number ")) 
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Returns 1 x 64 array of the bits of the floating point Number"))
	.Documentation(X_(R"(
The first bit is the sign bit. It is 0 for positive numbers and 1 for negative numbers.
The next 11 bits are the exponent plus the bias, 1022.
The remaining 52 bits are the base two decimal expansion of the significand.
Note the leading digit is always 1 and is omitted.
    )"))
);
_FP12* WINAPI
xll_float_bits(double x)
{
#pragma XLLEXPORT
	static xll::FP12 b(1, 64);

	union { double x; int64_t l; } u;
	u.x = x;

	for (unsigned short i = 0; i < 64; ++i)
		b[63 - i] = (u.l>>i)&1 ? 1 : 0;

	return b.get();
}

static AddInX xai_bits_float(
	FunctionX(XLL_DOUBLEX, X_("?xll_bits_float"), X_("BITS.FLOAT"))
	.Args({ 
		ArgX(XLL_FPX, X_("Bits"), X_("is an array of 64 bits "))
	})
	.Category(CATEGORY)
	.FunctionHelp(X_("Converts array of 64 bits to a floating point Number"))
	.Documentation(LR"(
        Return the bit composing a floating point number.
        The inverse function is FLOAT.BITS.
    )")
);
double WINAPI
xll_bits_float(const _FP12* pb)
{
#pragma XLLEXPORT

	union { double x; int64_t l; } u;

	try {
		ensure (size(*pb) == 64);
        u.l = 0;
        for (WORD i = 0; i < 64; ++i)
            if (pb->array[63 - i] != 0)
                u.l |= (1ll << i);
    }
	catch (const std::exception& ex) {
		XLL_INFO(ex.what());

		return std::numeric_limits<double>::quiet_NaN();
	}


	return u.x;
}