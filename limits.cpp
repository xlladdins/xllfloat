// limits.cpp - numerical limits
// Copyright (c) 2011 KALX, LLC. All rights reserved. No warranty is made.
#include "xllfloat.h"

#undef CATEGORY
#define CATEGORY X_("Float Limits")

using namespace xll;
/*
static AddInX xai_float_constants(
	Args(CATEGORY)
	.Documentation(
		X_("Various constants from &lt;climits&gt;." )
	)
);
*/
#define HASH(x) L#x
#define STR(x) HASH(x)
#if 0
//#define XLL_ENUM_DOC XLL_ENUM
// Integer
XLL_ENUM_DOC(CHAR_BIT, CHAR_BIT, CATEGORY, X_("number of bits in a char [") STR(CHAR_BIT) X_("]."), X_(" "));
XLL_ENUM_DOC(CHAR_MAX, CHAR_MAX, CATEGORY, X_("maximum char value [") STR(CHAR_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(CHAR_MIN, CHAR_MIN, CATEGORY, X_("mimimum char value [") STR(CHAR_MIN) X_("]."), X_(" "));
XLL_ENUM_DOC(INT_MAX, INT_MAX, CATEGORY, X_("maximum (signed) int value [") STR(INT_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(INT_MIN, INT_MIN, CATEGORY, X_("minimum (signed) int value [") STR(INT_MIN) X_("]."), X_(" "));
XLL_ENUM_DOC(LONG_MAX, LONG_MAX, CATEGORY, X_("maximum (signed) long value [") STR(LONG_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(LONG_MIN, LONG_MIN, CATEGORY, X_("minimum (signed) long value [") STR(LONG_MIN) X_("]."), X_(" "));
XLL_ENUM_DOC(SCHAR_MAX, SCHAR_MAX, CATEGORY, X_("maximum signed char value [") STR(SCHAR_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(SCHAR_MIN, SCHAR_MIN, CATEGORY, X_("minimum signed char value [") STR(SCHAR_MIN) X_("]."), X_(" "));
XLL_ENUM_DOC(SHRT_MAX, SHRT_MAX, CATEGORY, X_("maximum (signed) short value [") STR(SHRT_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(SHRT_MIN, SHRT_MIN, CATEGORY, X_("minimum (signed) short value [") STR(SHRT_MIN) X_("]."), X_(" "));
XLL_ENUM_DOC(UCHAR_MAX, UCHAR_MAX, CATEGORY, X_("maximum unsigned char value [") STR(UCHAR_MAX) X_("]."), X_(" "));
//XLL_ENUM_DOC(UINT_MAX, UINT_MAX, CATEGORY, X_("maximum unsigned int value [") STR(UINT_MAX) X_("]."), X_(" "));
//XLL_ENUM_DOC(ULONG_MAX, ULONG_MAX, CATEGORY, X_("maximum unsigned long value [") STR(ULONG_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(USHRT_MAX, USHRT_MAX, CATEGORY, X_("maximum unsigned short value [") STR(USHRT_MAX) X_("]."), X_(" "));

// Double
XLL_ENUM_DOC(DBL_DIG, DBL_DIG, CATEGORY, X_("number of decimal digits of precision [") STR(DBL_DIG) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_EPSILON, DBL_EPSILON, CATEGORY, X_("smallest such that 1.0+DBL_EPSILON != 1.0 [") STR(DBL_EPSILON) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_MANT_DIG, DBL_MANT_DIG, CATEGORY, X_("number of bits in mantissa [") STR(DBL_MANT_DIG) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_MAX, DBL_MAX, CATEGORY, X_("max value [") STR(DBL_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_MAX_10_EXP, DBL_MAX_10_EXP, CATEGORY, X_("max decimal exponent [") STR(DBL_MAX_10_EXP) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_MAX_EXP, DBL_MAX_EXP, CATEGORY, X_("max binary exponent [") STR(DBL_MAX_EXP) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_MIN, DBL_MIN, CATEGORY, X_("min positive value [") STR(DBL_MIN) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_MIN_10_EXP, DBL_MIN_10_EXP, CATEGORY, X_("min decimal exponent [") STR(DBL_MIN_10_EXP) X_("]."), X_(" "));
XLL_ENUM_DOC(DBL_MIN_EXP, DBL_MIN_EXP, CATEGORY, X_("min binary exponent [") STR(DBL_MIN_EXP) X_("]."), X_(" "));

// Float
XLL_ENUM_DOC(FLT_DIG, FLT_DIG, CATEGORY, X_("number of decimal digits of precision [") STR(FLT_DIG) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_EPSILON, FLT_EPSILON, CATEGORY, X_("smallest such that 1.0+FLT_EPSILON != 1.0 [") STR(FLT_EPSILON) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_MANT_DIG, FLT_MANT_DIG, CATEGORY, X_("number of bits in mantissa [") STR(FLT_MANT_DIG) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_MAX, FLT_MAX, CATEGORY, X_("max value [") STR(FLT_MAX) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_MAX_10_EXP, FLT_MAX_10_EXP, CATEGORY, X_("max decimal exponent [") STR(FLT_MAX_10_EXP) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_MAX_EXP, FLT_MAX_EXP, CATEGORY, X_("max binary exponent [") STR(FLT_MAX_EXP) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_MIN, FLT_MIN, CATEGORY, X_("min positive value [") STR(FLT_MIN) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_MIN_10_EXP, FLT_MIN_10_EXP, CATEGORY, X_("min decimal exponent [") STR(FLT_MIN_10_EXP) X_("]."), X_(" "));
XLL_ENUM_DOC(FLT_MIN_EXP, FLT_MIN_EXP, CATEGORY, X_("min binary exponent [") STR(FLT_MIN_EXP) X_("]."), X_(" "));

// fpclass()
XLL_ENUM_DOC(_FPCLASS_SNAN, FPCLASS_SNAN, CATEGORY, X_("signaling NaN [") STR(_FPCLASS_SNAN) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_QNAN, FPCLASS_QNAN, CATEGORY, X_("quiet NaN [") STR(_FPCLASS_QNAN) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_NINF, FPCLASS_NINF, CATEGORY, X_("negative infinity [") STR(_FPCLASS_NINF) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_NN, FPCLASS_NN, CATEGORY, X_("negative normal [") STR(_FPCLASS_NN) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_ND, FPCLASS_ND, CATEGORY, X_("negative denormal [") STR(_FPCLASS_ND) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_NZ, FPCLASS_NZ, CATEGORY, X_("-0 [") STR(_FPCLASS_NZ) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_PZ, FPCLASS_PZ, CATEGORY, X_("+0 [") STR(_FPCLASS_PZ) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_PD, FPCLASS_PD, CATEGORY, X_("positive denormal [") STR(_FPCLASS_PD) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_PN, FPCLASS_PN, CATEGORY, X_("positive normal [") STR(_FPCLASS_PN) X_("]."), X_(" "));
XLL_ENUM_DOC(_FPCLASS_PINF, FPCLASS_PINF, CATEGORY, X_("positive infinity [") STR(_FPCLASS_PINF) X_("]."), X_(" "));

XLL_ENUM_DOC(std::numeric_limits<double>::signaling_NaN(), SNAN, CATEGORY, X_("signaling NaN"), X_(" "));
XLL_ENUM_DOC(std::numeric_limits<double>::quiet_NaN(), QNAN, CATEGORY, X_("quiet NaN"), X_(" "));
XLL_ENUM_DOC(std::numeric_limits<double>::infinity(), PINF, CATEGORY, X_("positive infinity"), X_(" "));

#endif // 0