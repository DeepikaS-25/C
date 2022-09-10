/*
Name                    :   Deepika.S
Date                    :   26.07.2022
Description             :   Program to find factorial of given number using recursion
Sample execution        :   Enter the value of N: 4
                            Factorial of the given number is 24.
*/
#include <stdio.h>

int main()
{
    static int num, get = 0;                    //initialising num as static int since we need updated value each time after execution
    static unsigned long long int fact = 1;     //fact to hold factorial value
    if(num == 0)                                //if condiiton to get num only once
    {
        printf("Enter the value of N:");        //getting num and storing it
        scanf("%d", &num);
    }
    if(num < 0)                                 //condition to prompt error when entered num is negative
    {
        printf("Invalid input");
    }
    else if ((num == 0) || (num == 1))          //condition to terminate recursion
    {
        printf("Factorial of the given number is %lld.", fact);
    }
    else
    {
        fact = fact * num--;                    //finding factorial
        main();                                 //calling main function
    }
    return 0;

}
