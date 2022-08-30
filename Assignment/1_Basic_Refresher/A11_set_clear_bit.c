/*
Name                    :   Deepika.S
Date                    :   08.07.2022
Description             :   Program to check N th bit is set or not, If yes, clearing the M th bit
Sample input            :   Enter the number: 19

Sample output           :   Enter 'N': 1

                            Enter 'M': 4

                            Updated value of num is 3
*/

#include <stdio.h>

int main()
{
    unsigned int num, n, m, clear;          //declaring number, nth and mth bits and a clear dummy variable
    printf("Enter the number: ");
    scanf("%u", &num);                      //getting num from user and storing it
    printf("\nEnter 'N': ");
    scanf("%u", &n);                        //getting nth bit from user and storing it
    printf("\nEnter 'M': ");
    scanf("%u", &m);                        //getting mth from user and storing it
    
    if ((1 << n) == (num & (1 << n)))    //condition to check whether nth bit is set or not
    {
        clear = num & (~ (1 << m));           //if set then clearing the mth bit
        printf("\nUpdated value of num is %u ", clear);  //printing updated value
    }
    else
    {                                       //else printing output as num
        printf("\nUpdated value of num is %u ", num);
    } 
    return 0;
}
