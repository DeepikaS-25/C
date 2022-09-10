/*
Name                    :   Deepika.S
Date                    :   17.07.2022
Description             :   Program to replace 'n' bits of a given number
Sample execution        :   Enter num, n and val:15 2 1
                            Result = 13
*/

#include <stdio.h>

int replace_nbits(int, int, int);          //declaring a function of type integer to replace n bits of a number

int main()
{
    int num, n, val, res = 0;             //declaring number, no of bits and result variables
    
    printf("Enter num, n and val:");      //getting number, no of bits and value to replace from the user and storing it
    scanf("%d%d%d", &num, &n, &val);
    
    res = replace_nbits(num, n, val);     //calling replace_nbits function with parameters num, n and val
    
    printf("Result = %d\n", res);         //printing result returned from the function
}

int replace_nbits(int num, int n, int val)  //function definition
{
    return ( num & (~((1 << n) - 1))) |  ( val & ((01 << n) - 1 )) ;   // returning result

}

// (num & (~((1 << n) - 1))) |  (val & ((01 << n) - 1 )) 
 
// Here ( num & (~((1 << n) - 1))) ---------> clears bits in the given number for n bits

// ( val & ((01 << n) - 1 ))   --------->  gets n bits from the lsb of the value

// (num & (~((1 << n) - 1))) |  (val & ((01 << n) - 1 ))  -------> using or with above two results will set n bits at the lsb of num which has been cleared earlier
// Therefore n bits of num has been replaced by n bits of value
