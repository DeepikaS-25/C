/*
Name                    :   Deepika.S
Date                    :   17.07.2022
Description             :   Program to print 'n' bits from LSB of a number
Sample execution        :   Enter num, n:15 4
                            Binary form of 15 is 1 1 1 1
*/

#include <stdio.h>

int print_bits(int, int);                   //declaring a function of type integer to print 'n' bits lsb of given number

int main()
{
    int num, n;                             //declaring number, no of bits


    printf("Enter num, n :");             //getting number, no of bits from the user and storing it
    scanf("%d %d", &num, &n);

    printf("Binary form of %d:", num );
    print_bits(num, n);                     //calling print_bits function with parameters num, n

 }
int print_bits(int num, int n)              //function definition
{
    int print, loop;                        //declaring loop variable and print variable

       for (loop = n - 1; loop >= 0; loop--)    //for loop for n-1 times to print n bits
       {
            print = ( num >> loop ) & 1;       //passing loop-th bit by using a mask
            printf(" %d", print);           //printing nth bit each time
       }
    return 0;
}
