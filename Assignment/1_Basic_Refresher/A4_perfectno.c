/*
Name                    :   Deepika.S
Date                    :   03.07.2022
Description             :   Program to check if number is perfect or not
Sample input            :   Enter the value of 'n' : -2
Sample output           :   -2 is negative even number
*/

#include<stdio.h>

int main()
{
    int n, sum = 0;                 //declaring n and sum
    printf("Enter a number: ");
    scanf("%d", &n);                 //getting n from the user
    if ( n <= 0 )                   //if to check if entered is a positive no
    {
        printf("\nError : Invalid Input, Enter only positive number");
    }
    else                            //if positive then finding if it is perfect
    {
        int i;                      //declaring i for iteration
        for (i = 1; i < n; i++)         //for loop to find factors and to add factors
        {
            if ( n % i == 0)         //if to check iteration value is a factor
            {
                sum = sum + i;      //if condition is true then updating sum
            }
        }
        if (sum == n)             //if sum of factors equal to number entered then printing as n is perfect
        {
            printf("\nYes, entered number is perfect number");
        }
        else                        //if not printing not perfect no
        {
            printf("\nNo, entered number is not a perfect number");
        }
    }
    return 0;
}
