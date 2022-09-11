/*
Name                    :   Deepika.S
Date                    :   01.08.2022
Description             :   Program to reverse the given string using iterative method
Sample execution        :   Enter any string : EMERTXE
                            Reversed string is EXTREME
*/

#include <stdio.h>

void reverse_iterative(char str[]);       //function declaration

int main()
{
    char str[30];                                  //declaring string of size 30

    printf("Enter any string :");                 //getting string from the user and storing it
    scanf("%[^\n]", str);

    reverse_iterative(str);                 //function call

    printf("Reversed string is %s\n", str);       //printing reversed string after function modified the string
}

void reverse_iterative(char str[])              //function definition
{
    int i, temp, len;                           //declaring variables
    for(len = 0; str[len] != '\0'; ++len);        //finding length of the string

    for(i = 0; i < len/2; i++)          //loop to swap the elements till len/2 times since we are swapping two characters at a time
    {
        temp = str[i];                  //temp variable to store the char
        str[i] = str[len - i - 1];      //swapping 1st with last, 2nd with 2nd last till len/2
        str[len - i - 1] = temp;
    }
}
