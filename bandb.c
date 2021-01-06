#include <stdio.h>
#include <stdlib.h>
#include "bandb.h"
#include <string.h>

void getbytes(unsigned char dest[], int bytes, void *src, int reverse){
    // in order to copy the bytes from src to dest[] one byte at a time, we need to cast src to char* first ( char = 1 byte)
    unsigned char* source = src;
    int i = 0;
    int j = 0;
    // do not reverse 
    if( reverse == 0){

        // loop through the number of bytes 
        for (i = 0; i < bytes; i++)
        {
            // set source and dest to be equal ( copy )
            dest[i] = source[i];
        }
        // set dest to be null terminator to stop looping through the string
        dest[i] = '\0';

    }
    // if reverse is non zero, loop backward and copy from the end 
    else {
        for (i = bytes-1; i >= 0; i--)
        {
            // destination still has to start from 0
            dest[j] = source[i];
            j++;
        }
        dest[j] = '\0';
    }
}
void getbits(char dest[], int bytes, void *src, int start, int end){
    // declarations 
     int i = 0;
     int k = 0;
     int remainder = 0;
     int quotient = 0;
     int byte = 0;
     int value = 0;
     unsigned char* source = src;

     dest[0] = '\0';

     // loop throught the bytes from start to end
     for ( i = start; i > end; i--)
     {
         // remainder is number of bits in bytes
        remainder = i%8; 

         // quotient number of bytes for the bits;
        quotient = i/8; 

        byte =  quotient;

         // get the byte from memory
        value = source[byte];

         // shift to the right by remainder
        value = value >> remainder;

        // if its 0 we write '0' to dest, if its 1 then we write '1' to dest
        dest[k] = (value & 1) + '0';

        k = k + 1;
    }

     dest[k] = '\0';

}

// change from binary to decimal 
unsigned long long bits2ull( char *bits ){
    // declarations
    int i = 0;
    int number = 0;
    unsigned long long sum = 0;

    // loop through the length of bits available 
    for ( i = 0; i < strlen(bits); i++)
    {
        // ascii table shows 0 is 48, thus minus from that since we have 0 characters right now 
        number = (int) bits[i] - 48;
        unsigned long long pwr = strlen(bits);
        // if bit we are at is 1 then do the math and count it, otherwise ( 0 ) ignore 
        if( number == 1){
            sum = sum + power(pwr-i-1,2);
        }
    }
    return sum;
}

// change from binary to signed decimal of  2's complement
long long bits2ll( char *bits ){
    // declarations
    int i = 0;
    int number = 0;
    long long sum = 0;

    for ( i = 0; i < strlen(bits); i++)
    {
        // check the first binary number if its 1 then the decimal of it is negative 
        if (i == 0)
        {
            number = (int) bits[i] - 48;
            long long pwr = strlen(bits);
            if( number == 1)
            {
                // we are supposed to start from the right not left 
                sum = sum + signedPow(pwr-i-1,2);
                sum = sum*-1;
            }  
             // if the first binary number is not 1, then its 0 and thats means the decimal is positive
        } 
      else 
      {
        number = (int) bits[i] - 48;
        int pwr = strlen(bits);
        if( number == 1){
            sum = sum + signedPow(pwr-i-1,2);
        }        
      }        
        
    }
    
    return sum;
}
// get the power of the unsigned long long numbers 
unsigned long long power(unsigned long long power, unsigned long long base){
    int i = 0;
    if( power == 0) return 1;
    for ( i = 1; i < power; i++)
    {
        base = base * 2;

    }
    return base;
}

// get power of signed long long numbers 
long long signedPow(long long power, long long base){
    int i = 0;
    if( power == 0) return 1;
    for ( i = 1; i < power; i++)
    {
        base = base * 2;
    }
    return base;
}

void spff( char *sign, char *exponent, char *significand, float *src ){

    // variables declarations
    int bytes = 4;

    // convert float to unsigned int
    unsigned char* p = (unsigned char*) src;

    // retrieve exponent 
    getbits(exponent,bytes,p,30,22);

    // retrieve significand
    getbits(significand, bytes,p,22,-1);
    
    // retrieve sign 
    sign[0] = ((*p & 1) + '0');
    sign[1] = '\0';

}
void dpff(char *sign, char *exponent, char *significand, double *src){
    // declarations 
    int bytes = 8;

    // convert float to unsigned int
    unsigned char* p = (unsigned char*) src;

    // retrieve exponent 
    getbits(exponent,bytes,p,62,51);

    // retrieve significand
    getbits(significand,bytes,p,51,-1);
   
    // retrieve sign 
    sign[0] = ((*p & 1) + '0');
    sign[1] = '\0';
}
