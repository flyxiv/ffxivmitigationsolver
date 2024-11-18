/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef UTIL_CALCULATIONS_H
#define UTIL_CALCULATIONS_H

/*
 * For unsigned integer types, return 0 if lhs < rhs and lhs - rhs otherwise.
 */
#define WRAPPING_SUBTRACT(lhs, rhs) _Generic((lhs), \
	unsigned char: lhs < rhs ? 0 : lhs - rhs,       \
	unsigned short: lhs < rhs ? 0 : lhs - rhs,      \
	unsigned int: lhs < rhs ? 0 : lhs - rhs,        \
	unsigned long: lhs < rhs ? 0 : lhs - rhs,       \
	unsigned long long: lhs < rhs ? 0 : lhs - rhs,  \
	default: lhs - rhs)

#endif