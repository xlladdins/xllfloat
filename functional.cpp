// functional.cpp - STL <functional>
//#include "function.h"
#include "xll/xll.h"

#ifndef CATEGORY
#define CATEGORY "Function"
#endif
#ifndef dimof
#define dimof(x) sizeof(x)/sizeof(*x)
#endif

using namespace xll;

typedef xll::traits<XLOPERX>::xcstr xcstr;
typedef xll::traits<XLOPERX>::xfp xfp;
typedef xll::traits<XLOPERX>::xword xword;

static xcstr xav_sum[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_sum(
	X_("?xll_sum"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	X_("FUNCTION.ADD"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 + Arg2"),
	dimof(xav_sum), xav_sum
);
double WINAPI
xll_sum(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 + x2;
}

static xcstr xav_difference[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_difference(
	X_("?xll_difference"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	X_("FUNCTION.SUB"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 - Arg2"),
	dimof(xav_difference), xav_difference
);
double WINAPI
xll_difference(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 - x2;
}

static xcstr xav_product[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_product(
	X_("?xll_product"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	X_("FUNCTION.MUL"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 * Arg2"),
	dimof(xav_product), xav_product
);
double WINAPI
xll_product(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 * x2;
}

static xcstr xav_quotient[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_quotient(
	X_("?xll_quotient"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	X_("FUNCTION.DIV"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 / Arg2"),
	dimof(xav_quotient), xav_quotient
);
double WINAPI
xll_quotient(double x1, double x2)
{
#pragma XLLEXPORT

	double x = x1/x2;

	return x;
}

static xcstr xav_fmod[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_fmod(
	X_("?xll_fmod"), XLL_DOUBLE XLL_DOUBLE XLL_DOUBLE,
	X_("FUNCTION.FMOD"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns fmod(Arg1, Arg2) where fmod is the C standard library function."),
	dimof(xav_fmod), xav_fmod
);
double WINAPI
xll_fmod(double x1, double x2)
{
#pragma XLLEXPORT
	return x2 != 0 ? fmod(x1, x2) : std::numeric_limits<double>::quiet_NaN();
}

static xcstr xav_mod[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_mod(
	X_("?xll_mod"), XLL_LPOPERX XLL_LONG XLL_LONG,
	X_("FUNCTION.MOD"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 % Arg2. Not the same as Excel built-in MOD(Arg1, Arg2)"),
	dimof(xav_mod), xav_mod
);
LPOPERX WINAPI
xll_mod(LONG x1, LONG x2)
{
#pragma XLLEXPORT
	static OPERX o;

	if (x2 != 0) {
		o.xltype = xltypeNum;
		o.val.num = x1 % x2;
	}
	else {
		o.xltype = xltypeErr;
		o.val.err = xlerrValue;
	}

	return &o;
}

static xcstr xav_not[] = {
	X_("is the first argument")
};
static AddInX xai_not(
	X_("?xll_not"), XLL_WORDX XLL_WORDX XLL_WORDX,
	X_("FUNCTION.NOT"), X_("Arg"),
	CATEGORY, X_("Returns ~Arg"),
	dimof(xav_not), xav_not
);
WORD WINAPI
xll_not(WORD x)
{
#pragma XLLEXPORT

	return ~x;
}

static xcstr xav_and[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_and(
	X_("?xll_and"), XLL_WORDX XLL_WORDX XLL_WORDX,
	X_("FUNCTION.AND"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 & Arg2"),
	dimof(xav_and), xav_and
);
WORD WINAPI
xll_and(WORD x1, WORD x2)
{
#pragma XLLEXPORT

	return x1 & x2;
}

static xcstr xav_or[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_or(
	X_("?xll_or"), XLL_WORDX XLL_WORDX XLL_WORDX,
	X_("FUNCTION.OR"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 % Arg2"),
	dimof(xav_or), xav_or
);
WORD WINAPI
xll_or(WORD x1, WORD x2)
{
#pragma XLLEXPORT

	return x1 | x2;
}

static xcstr xav_xor[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_xor(
	X_("?xll_xor"), XLL_WORDX XLL_WORDX XLL_WORDX,
	X_("FUNCTION.XOR"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns Arg1 ^ Arg2"),
	dimof(xav_xor), xav_xor
);
WORD WINAPI
xll_xor(WORD x1, WORD x2)
{
#pragma XLLEXPORT

	return x1 ^ x2;
}

static xcstr xav_shift[] = {
	X_("is the argument whose bits are to be shifted"),
	X_("is number of bits to shifted to the left if positive or right if negative")
};
static AddInX xai_shift(
	X_("?xll_shift"), XLL_WORDX XLL_WORDX XLL_SHORTX,
	X_("FUNCTION.SHIFT"), X_("Arg, N"),
	CATEGORY, X_("Returns Arg << N or Arg >> N"),
	dimof(xav_shift), xav_shift
);
WORD WINAPI
xll_shift(WORD x, SHORT n)
{
#pragma XLLEXPORT

	return n > 0 ? x << n : n < 0 ? x >> -n : x;
}

static xcstr xav_equals[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_equals(
	X_("?xll_equals"), XLL_BOOL XLL_DOUBLE XLL_DOUBLE,
	X_("FUNCTION.EQUALS"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns true if Arg1 is equal to Arg2"),
	dimof(xav_equals), xav_equals
);
BOOL WINAPI
xll_equals(double x1, double x2)
{
#pragma XLLEXPORT

	return x1 == x2;
}

static xcstr xav_identity[] = {
	X_("is the argument to be returned")
};
static AddInX xai_identity(
	X_("?xll_identity"), XLL_DOUBLE XLL_DOUBLE,
	X_("FUNCTION.IDENTITY"), X_("Arg"),
	CATEGORY, X_("Returns Arg"),
	dimof(xav_identity), xav_identity
);
double WINAPI
xll_identity(double x)
{
#pragma XLLEXPORT

	return x;
}
/*
static xcstr xav_equals[] = {
	X_("is the first argument"),
	X_("is the second argument")
};
static AddInX xai_equals(
	X_("?xll_equals"), XLL_BOOL XLL_LPOPERX XLL_LPOPERX,
	X_("FUNCTION.EQUALS"), X_("Arg1, Arg2"),
	CATEGORY, X_("Returns true if Arg1 is equal to Arg2"),
	dimof(xav_equals), xav_equals
);
BOOL WINAPI
xll_equals(LPOPERX px1, LPOPERX px2)
{
#pragma XLLEXPORT

	return *px1 == *px2;
}

static xcstr xav_identity[] = {
	X_("is the argument to be returned")
};
static AddInX xai_identity(
	X_("?xll_identity"), XLL_LPOPERX XLL_LPOPERX,
	X_("FUNCTION.IDENTITY"), X_("Arg"),
	CATEGORY, X_("Returns Arg"),
	dimof(xav_identity), xav_identity
);
LPOPERX WINAPI
xll_identity(LPOPERX px)
{
#pragma XLLEXPORT

	return px;
}
*/