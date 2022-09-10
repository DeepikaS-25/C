/*
Name                    :   Deepika.S
Date                    :   19.07.2022
Description             :   Program to implement Circular left shift
Sample execution        :   Enter num: 12
                            Enter n : 3
                            Result in Binary:  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0
*/

#include <stdio.h>

int circular_left(int, int);        //function declaration for left shift
int print_bits(int);                //function declaration to print bits

int main()
{
    int num, n, ret;                //variables declaration

    //printf("Enter the num:");
    scanf("%d", &num);              //getting num and storing it

    //printf("Enter n:");
    scanf("%d", &n);                //getting n and storing it

    ret = circular_left(num, n);    //calling circular_left function and storing result in ret variable

    print_bits(ret);                //calling print_bits function to print bits
}

int circular_left(int num, int n)   //function definition
{
  return (num << n) | ((num >> (32 - n)) & ((1 << n) - 1));
}


int print_bits(int ret)             //function definition
{
    int loop, print;
    printf("Result in Binary:");
    for (loop = 31; loop >= 0; loop--)          //for loop to print 32 bits
    {
            print = ( ret >> loop ) & 1;        //passing loop-th bit by using a mask
            printf(" %d", print);               //printing nth bit each time
    }
    return 0;
}
//  (num << n) ----> shifting num n times
// ((num >> (32 - n)) & ((1 << n) - 1))-----> getting last n bits
// using bitwise or with above two result in circular left shift

