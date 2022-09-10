/*
Name                    :   Deepika.S
Date                    :   22.07.2022
Description             :   Program to generate negative Fibonacci numbers using recursion
Sample input            :   Enter a number: 8
Sample input            :   0, 1, -1, 2, -3, 5, -8
*/

#include <stdio.h>

void negative_fibonacci(int, int, int, int);            //function definition

int main()
{
    int limit;                                          //declaring variables

    //printf("Enter the limit : ");
    scanf("%d", &limit);                                //getting limit and storing it

    negative_fibonacci(limit, 0, 1, 0);                 //function call with arguments limit, first, second and next element
    return 0;
}

void negative_fibonacci(int limit, int first, int second, int next) //function definition
{
    if (limit > 0)                                      //prompting error when limit entered is a positive value
    {
        printf("Invalid input");
    }
    else if (next >= limit)                             //condition to exit recursion
    {
        if(((next < 0) && (-next <= -limit)) || (next <= -limit))   //condition to print elements upto given limit
        {
           if(next != 0)                                   //printing comma
            {
                printf(", ");
            }
        printf("%d", next);                      //printing sequence
        }
        first = second;
        second = next;
        next = first - second;                          //generating elements by subtracting previous two elements
        negative_fibonacci(limit, first, second, next); //function calling recursively
    }
}
