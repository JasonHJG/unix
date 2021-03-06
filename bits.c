/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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

#include "btest.h"

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
id_struct studentID =
{
  /* UID number: */
  "004478540",
  /* Last Name: */
  "He",
  /* First Name: */
  "Jingang",
};

#if 0
/*
 * Instructions to Students:
 *
 * STEP 2: Read the following instructions carefully.
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest harness to check your solutions for correctness.
 */


#endif
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
       /*
   notice that C=A^B will return the same oddity of 0
   we thus can use this and split the number
       */
       int half1 = x>>16;
       int result1 = x ^ half1;
       /* the right 16 degits determine */

       
       int half2 = result1 >> 8;
       int result2 = result1 ^ half2;
       /* right 8 */

       
       int half3 = result2 >>4;
       int result3 = result2 ^ half3;
       /* right 4 */

       int half4 = result3 >>2;
       int result4 = result3 ^ half4;
       /* right 2 */

       int temp = (result4>>1)^(result4);
       int result=temp & 1;
  return result ;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
 
  int part1= x >> n;
  int part2=( x <<(32+(~n))) << 1;
  int complement=((~0) << (32+(~n)))<< 1;
  int part3= part1 & (~ complement);
  
  return (part2 | part3);
  
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {

 
  int s1=0xff << (n << 3);
  int s2=0xff << (m << 3);
  int k1=s1 & x;
  int k2=s2 & x;
  int p1=(k1 >>( n<<3)) & 0xff;
  int p2=(k2 >>( m<<3)) & 0xff;
  int r1=p1 << (m << 3);
  int r2=p2 << (n << 3);
  int r3=(~(s1 | s2)) & x;
  return (r1 | r2 | r3);
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
  int temp1= x & ((~ 1)<< 14 );
  int temp= 1<< 15;
  int temp2= temp1 + (temp);
  int temp3= temp2 & (~temp);

  return !(temp3);
  
}
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*
if 1,1 or 0,0   =>  0,0  or 1,1  =>  0 => 1 
if 0,1 or 1,0   => 1,0   or 0,1  => 1  => 0 
  */
  int x1= ~x;
  int y1= ~y;
  int temp= x1 | y1;
  
  return ~(temp);
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /*
sign_x=(x>>31)&1  // 0 or 1
sign_y=(y>>31)&1  // 0 or 1
0,0 ok
1,1 ok
1,0 may not ok    Tmin-sth
0,1 may not ok    Tmax+sth

x-y  if x -, y+, should have -
x-y  if x +, y-, should have +
  */
  int signX= (x>>31) & 1;
  int signY= (y>>31) & 1;
  int diff= x+ (~ y +1);
  int sign= (diff >> 31) & 1;
  int conFirst= sign ^ signX;
  int conSecond= signX ^ signY;
  return !(conFirst & conSecond);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int signX=1 & (x>>31);
  int signY=1 & (y>>31);
  int diff= signX ^ signY;
  int conFirst= diff &(1 & (1+ signX));
  int sign=(y+( ~x +1)) >> 31;
  int conSecond=sign &(1& (1+ diff));
  return conFirst | conSecond;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift= 32+(~n+1);
  int temp= x << shift;
  int result= temp >> shift;
  
  return !(result ^ x) ;

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*
easy for Tmax ~ -Tmax
use ~x+1;
but if Tmin, there is a problem! 
simply no way to express!
  */
  return ~x+1;  

  
}/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /*
  Tmax= 0111 1111
  Tmin= 1000 0000
  Tmax  ^ Tmin=1111 1111=-1
  !(-1+1)=1
  !(others+1)=0
  */
  int Tmin=x+1;
  int bool=!(Tmin);
  int min=Tmin | bool;
  int test=min + x;
  return !(test+1);
  
}
