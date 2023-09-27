/*
 * CS:APP Data Lab
 *
 * <hollowgl>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // correct but illegal
    // return (~x & y) | (x & ~y);
    return ~(~(~x & y) & ~(x & ~y));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) { return 1 << 31; }
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // return !(~((x + 1) ^ x));
    int a = (~((x + 1) ^ x)); // a == 0000 only if x == 0111 or 1111
    int b = !(x + 1);         // b == 1 only if x == 1111
    return !(a + b);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    int mask = 0xAA | (0xAA << 8);
    mask = mask | (mask << 16);
    return !((x & mask) ^ mask);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { return ~x + 1; }
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0'
 * to '9') Example: isAsciiDigit(0x35) = 1. isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // notice that:
    //   x - '0' >= 0
    //   x - '9' - 1 < 0
    int left = !((x + ~0x30 + 1) >> 31);
    int right = ((x + ~0x39) >> 31);
    return left & right;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // notice that
    // !x - 1 == 0 if x = 0, or equals 0xffff
    int cond = !x + ~1 + 1;
    int isY = y & cond;
    int isZ = z & ~cond;
    return isY | isZ;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    // ?0 should be 1 if ? < 0
    int x0 = (x >> 31) & 0x1;
    int y0 = (y >> 31) & 0x1;
    // 0? should be 1 if ? >= 0
    int _0x = (!(x >> 31) & 0x1);
    int _0y = (!(y >> 31) & 0x1);

    // x0y should be 1 if x < 0 and y >= 0
    int x0y = x0 & _0y;
    // y0x shoule be 1 if y < 0 and x >= 0
    int y0x = y0 & _0x;
    // xy0 shoule be 1 if they are both < 0
    int xy0 = x0 & y0;
    // _0xy shoule be 1 if they are both >= 0
    int _0xy = _0x & _0y;

    int cond = ((x + ~y) >> 31) & 0x1;
    return (x0y & (!y0x)) | (cond & (xy0 | _0xy));
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
    // I think this is a direct solutioin, but it exceed the Max-ops limit
    // int low16 = x | (x >> 16);
    // int low8 = low16 | (low16 >> 8);
    // int low4 = low8 | (low8 >> 4);
    // int low2 = low4 | (low4 >> 2);
    // int low1 = low2 | (low2 >> 1);
    // low1 = low1 & 0x1;
    // return ~low1 + 2;

    // x ^ (x - 1) is "magic", it clear the rightmost set bit
    int zeorOne = x ^ (x + ~1 + 1);
    int not0x8 = (~x >> 31) & 0x1;
    return ((zeorOne >> 31) & 0x1) & not0x8;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {

    // bx shoule be 1 if the 1 exits in the leftmost x bit of 32 bit
    int b16, b8, b4, b2, b1;
    int sign = (x >> 31) & 0x01;
    // y should be x if x is positve, or ~x negative
    int y = (x & (~1 + 1 + sign)) | (~x & (~sign + 1));
    int is_0_or_neg_1 = !y; // not_neg_1 should be 1 if x euquals -1 or 0
    int rightmost_one = 0;

    // for positive num, find the leftmost 1
    b16 = !!(y >> 16);
    y = (y >> (b16 << 4)) & (0xff | 0xff << 8);
    b8 = !!(y >> 8);
    y = (y >> (b8 << 3)) & 0xff;
    b4 = !!(y >> 4);
    y = (y >> (b4 << 2)) & 0xf;
    b2 = !!(y >> 2);
    y = (y >> (b2 << 1)) & 0x3;
    b1 = !!(y >> 1);
    rightmost_one = (b16 << 4) + (b8 << 3) + (b4 << 2) + (b2 << 1) + b1 + 1;

    // for negative num, find the leftmost 0
    // In fact, if z = ~x, then the leftmost 1 of z should be the leftmost 0 of
    // x

    // special case 1: howmanybits(0) should be 1, not 2
    // special case 2: howmangybits(-1) should be 1, not 2

    return rightmost_one + 1 + (~is_0_or_neg_1 + 1);
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sigh = uf >> 31;
    unsigned exp = (uf >> 23) & 0xff;
    // denormalized num: 0 and values cloes to 0
    if (exp == 0) {
        return (uf << 1) + (sigh << 31);
    }
    // special num: infinity, NaN
    if ((exp ^ 0xff) == 0) {
        return uf;
    }
    // normalized num
    return uf + (1 << 23);
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) { // How ugly my solution is :(
    unsigned sign = uf >> 31;
    unsigned exp = (uf >> 23) & 0xff;
    unsigned frac = uf & 0x7fffff;
    int r_exp, abs;

    // denomalized num
    if (exp == 0) {
        return 0;
    }
    // special num
    if ((exp ^ 0xff) == 0) {
        return 0x80000000u;
    }
    // normalized num
    r_exp = exp - 127;
    // overflow
    if (sign == 0 && r_exp >= 31) {
        return 0x80000000u;
    } else if (sign && (r_exp > 31 || (r_exp == 31 && frac != 0))) {
        return 0x80000000u;
    } else if (r_exp < 0) { // too small
        return 0;
    }
    abs = (0x800000 | frac);
    if (r_exp >= 23) {
        abs = abs << (r_exp - 23);
    } else {
        abs = abs >> (23 - r_exp);
    }
    if (sign == 0) {
        return abs;
    } else {
        return -abs;
    }
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) { 
    if (x > 127) {
        return 0xff << 23;
    } else if (x < -126) {
        return 0;
    }
    return (x + 127) << 23;
}
