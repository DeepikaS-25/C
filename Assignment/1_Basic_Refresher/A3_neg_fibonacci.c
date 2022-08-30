/*
Name                    :   Deepika.S
Date                    :   04.07.2022
Description             :   Program to generate positive Fibonacci numbers
Sample input            :   Enter a number: 8
Sample output           :   0, 1, -1, 2, -3, 5, -8
*/

#include<stdio.h>

int main()
{
    int num;         //declaring num as integer
    //printf("Enter a number: ");       //receiving num to print fibonacci series
    scanf("%d", &num);                  //storing in num variable
    if (num > 0)                        //if positive number entered printing output as invalid input
    {
        printf("\nInvalid input");
    }
    else                     //else negative integer is entered then printing fibonacci series
    {
        int first = 0, second = 1, next = 0;        //declaring first element as 0 and second as 1 and next as 0
        while (next >= num && -next >= num)              //as long as condition is true steps are executed
        {
            if(next != 0)
            {
                printf(", ");                             //printing comma
            }
            printf("%d", next);           //printing next element
            first = second;                //changing second to first and next to second
            second = next;
            next = first - second;        //next element is subtraction of previous two elements
        }
    }
    return 0;
}
