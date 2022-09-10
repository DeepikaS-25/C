/*
Name                    :   Deepika.S
Date                    :   22.07.2022
Description             :   Program to implement own is_xdigit() function
Sample execution        :   Enter a character: a
                            Entered character is an hexadecimal digit
*/
#include <stdio.h>

int is_xdigit(int);                       //function declaration

int main()
{
    char ch;                              //declaring variables
    short ret;

    printf("Enter a character: ");
    scanf("%c", &ch);                     //getting character and storing it

    ret = is_xdigit(ch);                 //calling is_xdigit function with ch argument
                                         //using ternary operator to print output if ch is returned
    (ret != 0) ? printf("Entered character is an hexadecimal digit") : printf("Entered character is not an hexadecimal digit");
    return 0;
}
int is_xdigit(int ch)                    //function definition since int ch is passed ascii equivalent will be passed
{
    if(((ch >= 'a') && (ch <= 'f')) || ((ch >= 'A') && (ch <= 'F')) ||  ((ch >= '0') && (ch <= '9')))     //if lowercase,uppercase and decimal numbers
    {
        return ch;                         //returning ch
    }
    else
    {
        return 0;                          //else returning 0
    }
}