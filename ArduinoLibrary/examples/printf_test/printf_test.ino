//============================================================
// Serial Arduino Demonstration.
//============================================================
// This should (!) work very similarly to the Arduino Serial
// interface. It can be used in the Arduino IDE, or in AVR
// code written, for example, under PlatformIO.
//
// Norman Dunbar
// 7th August 2020.
//============================================================



//============================================================
// Saving program space and size
//============================================================
// Uncomment one or more of the following to disable that
// particular option from the build. This will help save space
// in the final executable file.
//
// For example, if you don't need floating point numbers in 
// your code, uncomment the line with 
// PRINTF_DISABLE_SUPPORT_FLOAT to define it.
//============================================================
//#define PRINTF_DISABLE_SUPPORT_FLOAT
//#define PRINTF_DISABLE_SUPPORT_EXPONENTIAL
//#define PRINTF_DISABLE_SUPPORT_LONG_LONG
//#define PRINTF_DISABLE_SUPPORT_PTRDIFF_T


#include "printf.h"

//------------------------------------------------------------
// In order to get the output to go to Serial, we need to 
// define a function, _putchar(), to send each character to 
// Serial. This will be called from the library.
//------------------------------------------------------------
void _putchar(char character)
{
  Serial.print(character);
}



//------------------------------------------------------------
// Now we have to setup the serial interface etc, as normal.
//------------------------------------------------------------
void setup() {
    // 115200 baud, 8 data bits, 1 stop, no parity.
    Serial.begin(115200);

    // A little bit of text and flush it out.
    printf("Hello World!\n");
    Serial.flush();

    // Some numbers, with mandatory sign character
    // each in 2 spaces (for the digits)
    for (byte x = -10; x < 11; x++) {
        printf("X=%+2i  ", x);
    }
    printf("\n");


    unsigned int testNumber = 12345;


    printf("\n========================");
    printf("\nPositive integer numbers\n");
    printf(  "========================\n\n");

    printf("     Binary: %d = 0b%0.16b\n", testNumber, testNumber);
    printf("      Octal: %d = 0%o\n", testNumber, testNumber);
    printf("    Decimal: %d = %05d\n", testNumber, testNumber);
    printf("Hexadecimal: %d = 0x%4x\n", testNumber, testNumber);

    printf("\n========================");
    printf("\nNegative integer numbers\n");
    printf(  "========================\n\n");

    printf("     Binary: %d = 0b%0.16b\n", -testNumber, -testNumber);
    printf("      Octal: %d = 0%o\n", -testNumber, -testNumber);
    printf("    Decimal: %d = %5d\n", -testNumber, -testNumber);
    printf("Hexadecimal: %d = 0x%4x\n", -testNumber, -testNumber);


//------------------------------------------------------------
// Floats use a large amount of memory. Best avoided.
//------------------------------------------------------------
#ifndef PRINTF_DISABLE_SUPPORT_FLOAT

    // Floating point?
    float testFloat = 123.456;

    // Rounding to various precisions.
    printf("\n========================");
    printf("\nFloating point precision\n");
    printf(  "========================\n\n");

    for (byte rounding = 0; rounding < 5; rounding++) {
        printf("%3.3f displayed with %d decimal places = %10.*f\n", testFloat, rounding, rounding, testFloat);
    }

    // Which way is rounding done? It appears to be if the
    // final digit is < 5, rounds down, otherwise, rounds up.

    // Rounds DOWN to 123.42
    printf("\n=======================");
    printf("\nFloating point rounding\n");
    printf(  "=======================\n\n");

    testFloat = 123.422;

    // Print floats in 7 character positions with 2
    // digits after the decimal point. Leading zeros
    // will be displayed to fill all 7 spaces. 1 space
    // is reserved for the decimal point.
    // nnnn.nn is the output format.
    printf("123.422: %07.2f (rounds down)\n", testFloat);

    // Rounds UP to 123.43
    testFloat = 123.425;
    printf("123.425: %07.2f (rounds up)\n", testFloat);

    // Rounds UP to 123.43
    testFloat = 123.426;
    printf("123.426: %07.2f (rounds up)\n\n", testFloat);

#endif  // PRINTF_DISABLE_SUPPORT_FLOAT

    // Are we returning the correct number of characters
    // printed?
    int nc = printf("\n\nHello from printf.\n");
    printf("The message above returned %d characters"
           " \\n counts as 1 on Linux. "
           "And there were three in that message.\n",
           nc);

    printf("\nAnd now, let's run the loop() function a few (million) times!\n");
}


void loop() {
    // Increment the counter each time around the loop.
    static unsigned int counter = 0;

    printf("\nThe value of counter, the number of times loop() has been called, is %05u.", ++counter);
    delay(500);
 }
