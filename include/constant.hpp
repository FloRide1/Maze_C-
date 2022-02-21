#pragma once

// Macro:
#define IS_TRUE(x) ((x) == true)
#define IS_FALSE(x) ((x) == false)

#define IS_NULL(x) ((x) == NULL)
#define NOT_NULL(x) ((x) != NULL)

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define IS_EQUAL(x, y) (COMPARE(x, y) == 0)
#define IS_BIGGER(x, y) (COMPARE(x, y) == 1)
#define IS_LESSER(x, y) (COMPARE(x, y) == -1)

#define SIGN(x) COMPARE(x, 0)
#define IS_POS(x) (SIGN(x) == 1)
#define IS_NEG(x) (SIGN(x) == -1)
#define IS_ZERO(x) (SIGN(x) == 0)

#define ABS(x) (IS_NEG(x) ? -(x) : (x))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define GET_BIT(a, b) ((a) & (1 << (b)))
#define SET_BIT_ON(a, b) ((a) | (1 << (b)))
#define SET_BIT_OFF(a, b) ((a) & ~(1 << (b)))
#define SET_BIT(a, b, c) ((c) ? SET_BIT_ON(a, b) : SET_BIT_OFF(a, b))

// Constants
#define S_NEW_LINE "\n"
