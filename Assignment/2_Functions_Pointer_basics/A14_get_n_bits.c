/*
Name                    :   Deepika.S
Date                    :   17.07.2022
Description             :   Program to get 'n' bits of a given number
Sample execution        :   Enter num and n:10 3
                            Result = 2
*/

#include <stdio.h>

int get_nbits(int, int);            //declaring a function of type integer to get n bits of a number

int main()
{
    int num, n, res = 0;            //declaring number, no of bits and result variables

    printf("Enter num and n:");     //getting number and no of bits from the user
    scanf("%d%d", &num, &n);

    res = get_nbits(num, n);        //calling get_nbits function with parameters num and n

    printf("Result = %d\n", res);   //printing result returned from the function
}

int get_nbits(int num, int n)       //function definition
{
    return num & ((01 << n) - 1 );  // returning result
}

// num & ((01 << n) - 1 ) ---> ((01 << n) - 1 ) will give ones only at the n bits
// num & mask ---> using bitwise and with mask will give values only at the n bits


