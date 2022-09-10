/*
Name                    :   Deepika.S
Date                    :   19.07.2022
Description             :   Program to implement Circular right shift
Sample execution        :   Enter num: 12
                            Enter n : 3
                            Result in Binary: 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
*/

#include <stdio.h>

int circular_right(int, int);       //function declaration for right shift
int print_bits(int);                //function declaration to print bits

int main()
{
    int num, n, ret;                //variables declaration

    //printf("Enter the num:");
    scanf("%d", &num);              //getting num and storing it

    //printf("Enter n:");
    scanf("%d", &n);                //getting n and storing it

    ret = circular_right(num, n);   //calling circular_right function and storing result in ret variable

    print_bits(ret);                //calling print_bits function to print bits
}
int circular_right(int num, int n)  //function definition
{
    return (~(((1 << n) - 1) << (32 - n)) & (num >> n) ) | ((num  & ((1 << n) - 1)) << (32 - n));
}

int print_bits(int ret)             //function definition
{
    int loop, print;
    printf("Result in Binary:");
    for (loop = 32 - 1; loop >= 0; loop--)    //for loop to print 32 bits
    {
            print = ( ret >> loop ) & 1;      //passing loop-th bit by using a mask
            printf(" %d", print);             //printing nth bit each time
    }
    return 0;
}

// (~(((1 << n) - 1) << (32 - n)) & (num >> n) ) ----> shifting num n times and clearing first n bits
// ((num  & ((1 << n) - 1)) << (32 - n)) -----> getting last n bits
// using bitwise or with above two result in circular right shift


