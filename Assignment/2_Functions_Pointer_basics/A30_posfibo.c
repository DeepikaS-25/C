/*
Name                    :   Deepika.S
Date                    :   22.07.2022
Description             :   Program to generate positive Fibonacci numbers using recursion
Sample input            :   Enter a number: 8
Sample input            :   0, 1, 1, 2, 3, 5, 8
*/

#include <stdio.h>

void positive_fibonacci(int, int, int, int);                //function declaration

int main()
{
    int limit;                                              //declaring limit variable

    //printf("Enter the limit : ");                         //getting limit and storing it
    scanf("%d", &limit);

    positive_fibonacci(limit, 0, 1, 0);                     //function call with arguments limit, first, second and next element
    return 0;
}

void positive_fibonacci(int limit, int first, int second, int next)     //function definiton
{
    if (limit < 0)                                          //prompting error when limit entered is negative
    {
        printf("Invalid input");
    }
    else if (next <= limit)                                 //condition to exit recursion
    {
        if(next != 0)
        {
            printf(", ");                             //printing first element
        }
        printf("%d", next);                             //printing sequence
        first = second;
        second = next;
        next = first + second;                              //generating elements by adding previous two elements
        
        positive_fibonacci(limit, first, second, next);     //function calling recursively
    }
}
