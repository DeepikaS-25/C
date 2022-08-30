/*
Name                    :   Deepika.S
Date                    :   08.07.2022
Description             :   Program to count number of set bits in a given number and print parity
Sample input            :   Enter the number: 7

Sample output           :   Number of set bits = 3

                            Bit parity is Odd
*/

#include <stdio.h>

int main()
{
    unsigned int num, count = 0;  //declaring num and initialising count
    printf("Enter the number: ");
    scanf("%u", &num);             //getting no and storing it

    do
    {
        if (num & 01)             //condition to find no of ones in num
        {
            count++;                //updating when condition is true
        }
        num = num >> 1;             //shifting num and updating
    } while (num != 0);             //condition to run the loop until num is zero

    printf("\nNumber of set bits = %d\n",count);  //printing count

    if (count & 1)                  //condition to check parity if last digit is one then odd
    {
      printf("\nBit parity is Odd");
    }
    else                            //else even
    {
       printf("\nBit parity is Even");
    }
    return 0;
}

