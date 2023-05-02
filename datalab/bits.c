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
/*
and  x y x&y x|y x ^ y x
     0 0  0   0   0
     0 1  0   1   1
     1 0  0   1   1
     1 1  1   1   0 */
//1
/*
 * bitAnd - x&y using only ~ and |   
 *   Example: bitAnd(6, 5) = 4   0110
 *   Legal ops: ~ |              0111
 *   Max ops: 8                  0110
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y); //? ley de morgan
}
/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6 
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y) {
  return (~x & ~y)|(x & y);
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return ((~x) & (~y)); //? ley de morgan
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    return ~(~(~x & y) & ~(x & ~y));
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
     Posicion  31 30 29 28                               3  2  1  0
     FFFFFFFD = 1  1  1  1 1111 1111 1111 1111 1111 1111 1  1  0  1
     devuelve = 1  0  1  0 1010 1010 1010 1010 1010 1010 1  0  1  0 

     Mask       0000 ........0000 0000 0000         1010    1010
    &
     Resultado: 0000.........0000 0000 0000         1010    1000      : A8                                         
     argumen:   
     MASK :     1  0  1  0  1  0  1 0
     int = MASK : 0000 ........0000 0000 0000 1010 1010
     Resultado:
 *   Legal ops: ! ~ & ^ | + << >> 
 *   Max ops: 12
 *   Rating: 2

    //Devuelve 1 si todos los bits en posiciones impares en una palabra seteada a 1 
 */
int allOddBits(int x) {

    int mask = 0xAA;
    mask = mask | (mask << 8);
    mask = mask | (mask << 16);
    return !((x & mask) ^ mask);
}
/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
    int mask = 0x55;
    mask = mask | (mask << 8);
    mask = mask | (mask << 16);
    return !!(x & mask);
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
    int mascara = 0xFF;
    int byte_n = ((x >> (n << 3)) & mascara);
    int byte_m = ((x >> (m << 3)) & mascara);
    int mascara_n = mascara << (n << 3);
    int mascara_m = mascara << (m << 3);
    return (x & ~mascara_n & ~mascara_m) | (byte_n << (m << 3)) | (byte_m << (n << 3));
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
    int shifteador = 33 + ~n;
    return !(((x << shifteador) >> shifteador) ^ x);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    return ~(x) + 1;
}
/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    //? Se shiftea hasta poner el bit de signo en el primer bit y después lo convierto en el valor correspondiente dependiendo del signo para devolverlo.
    return (x >> 31) | !(!x);
}
//3
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
   /*
    * el overflow sucede si:
    * 1) x e y tienen signos diferentes
    * 2) res = x - y tiene diferente signo con x
    */

  int z=x+y;
  int a=x>>31;
  int b=y>>31;
  int c=z>>31;

  return (!(!(a^b)))|(!(a^c)&!(b^c));
}
  /*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38   0000 0101  0x5
                                     0000 0011  0x3
                                     0011 1000  0x38


 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  //? cambia todos los 1 que quedan por bit bajo
  int low = ~0<<lowbit;
  //? cambia todos los 1 a la derecha por bit alto
  int high = ~0<<highbit;
  //? cambiar highbit sobre 1 más y luego lo complementa
  high = ~(high << 1);

  return high&low;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4    r: 0000 0000... 0101
                             x: 0010
                             y: 0100
                             z: 0101
                             ........
                             r: 0100
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    //? si x != 0, restar 1 de 0 => 0xffffffff de lo contrario, si x = 0, reste 1 de 1 => 0x00000000
    int mask = (!x + ~0x00);

    //? si x no es cero, enmascarar z, si fuera cero, enmascarar y
    return ((~mask) & z) | ((mask) & y);
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {

  int limInf = 0x30;
  int limSup = 0x3a;

  return (!((x + (~limInf+ 1)) >> 31)) & (x + (~limSup+ 1)) >> 31;
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int signoX = x >> 31;
  int signoY = y >> 31;
  int igual = (!(signoX ^ signoY)) & ((~y + x) >> 31);
  int desiguales = signoX & !signoY;
  return !(igual | desiguales);
 }
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  int mascara = 0xff;
  mascara = mascara << (n << 3);
 
  return (x & ~mascara) | c << (n << 3);
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int signoX = x >> 31;
  int mask = signoX;
  int suma = x + mask;
  return (suma ^ mask);
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */


int bang(int x) {
  int i = ~x;
  int j = i + 1;
  x = ( (~j& i) >> 31) & 1;

  return x;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {
  int mascara = x + (~(0x80 << 24));
  mascara = x | mascara;
  x = mascara >> 31;
  
  return x & 1;
}
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  int i = ~x;
  int j = i + 1;
  x = ( (~j& i) >> 31) & 1;

  return x;
}
/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */

unsigned floatAbsVal(unsigned uf) {
  unsigned x = uf & 0x7fffffff;
  if(x > 0x7f800000)
  return uf;
  else return x;
}

/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) {
    unsigned a = uf<<1;
    unsigned b = ug<<1;
    unsigned c = !!((uf << 9)&~0);
    unsigned d = !!((ug << 9)&~0);
    unsigned e = !((a>>24)^0xff);
    unsigned f = !((b>>24)^0xff);

    if(!(a|b))//? +0 -0
      return 1;
    if((c&e)||(d&f))//? nan
      return 0;
    if(!(uf^ug))
      return 1;
    return 0;
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    unsigned exponente = (uf >> 23) & 0xFF; //? Consigo el exponente de 8 bits
    unsigned mantisa = uf << 9; //? consigo la mantisa de 23 bits

    if(exponente == 0xFF && mantisa != 0x00){ //? Si es NaN, el exp es 111...1 y la mantisa no es 000...0.
        return uf;  //? Si es NaN lo devuelvo tal cual.
    }

    return uf ^ (1<<31); //? Si no, hago las op pertinentes para cambio de signo.
}
/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    //? Consigo las 3 partes de cada numero.
    unsigned int signo_uf = uf >> 31;
    unsigned int exponente_uf = (uf >> 23) & 0xFF;
    unsigned int mantisa_uf = uf & 0x7FFFFF;

    unsigned int signo_ug = ug >> 31;
    unsigned int exponente_ug = (ug >> 23) & 0xFF;
    unsigned int mantisa_ug = ug & 0x7FFFFF;

    //? Si alguno es NaN devuelvo 0. Si es NaN, el exp es 111...1 y la mantisa no es 000...0.
    if(((exponente_uf == 0xFF) && (mantisa_uf != 0)) || ((exponente_ug == 0xFF) && (mantisa_ug != 0))) return 0;
    //! -3

    //? Si exponente y mantisa de ambos numeros son 0, devuelvo 0 (falso) porque los dos numeros son 0.
    if((exponente_uf + mantisa_uf == 0) && (exponente_ug + mantisa_ug == 0)) return 0;
    //! -2

    //? Si tienen diferente signo, devuelvo el resultado de comparar el signo de uf con 1. Si signo_uf == 1, entonces uf es menor a ug.
    if(signo_uf != signo_ug) {
        return (signo_uf == 1);
    }

    //? Si ambos numeros son negativos, el que tenga el exponente mas chico sera mas grande
    if(signo_uf == 1 && (exponente_uf != exponente_ug)){
        return (exponente_uf > exponente_ug);
    }

    //? Si ambos numeros son positivos, el que tenga el exponente mas grande sera mas grande
    if((exponente_uf != exponente_ug)) return (exponente_uf < exponente_ug);
    //! -2

    //? Si tienen mismo signo y exponente, pero diferente mantisa, me fijo en el bit de signo para ver que devuelvo, igual que como hice con los exponentes.
    if(signo_uf) return (mantisa_uf > mantisa_ug);
    
    return (mantisa_uf < mantisa_ug);
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
int floatFloat2Int(unsigned uf) {
    int exponent = (uf >> 23) & 0xff;
    int exp = exponent - 127;
    int frac = uf & 0x7fffff;

    if(exponent == 0x7F800000)
        return 0x80000000u;
    if(!exponent)
        return 0;
    if(exp < 0)
        return 0;
    if(exp > 30)
        return 0x80000000u;

    frac = frac | 0x800000;
    if (exp >= 23)
        frac = frac << (exp - 23);
    else
        frac = frac >> (23 - exp);

    if((uf >> 31) & 1)
        return ~frac + 1;

    return frac;
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
    if (x < -149)
        return 0;
    //? denorm
    if (x < -126)
        return 1 << (149 + x);
    //? norm
    if (x < 128)
        return (x + 127) << 23;
    //? inf
    return 0x7f800000;
}