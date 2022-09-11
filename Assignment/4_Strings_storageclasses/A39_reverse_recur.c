/*
Name                    :   Deepika.S
Date                    :   01.08.2022
Description             :   Program to reverse the given string using recursive method
Sample execution        :   Enter any string : EMERTXE
                            Reversed string is  EXTREME
*/

#include <stdio.h>

void reverse_recursive(char str[], int ind, int len);       //function declaration

int main()
{
    char str[30];                                   //declaring string of size 30
    
    printf("Enter any string : ");                  //getting string from the user and storing it
    scanf("%[^\n]", str);
    int len;
    for(len = 0; str[len] != '\0'; ++len);          //finding length of the string

    reverse_recursive(str, 0, len);                 //function call

    printf("Reversed string is %s\n", str);         //printing reversed string after function modified the string
}

void reverse_recursive(char str[], int ind, int len)    //function definition
{
    int temp;                               //declaring temp as temporary variable
    
    if(ind < len/2)                         //condition to swap characters len/2 times since we are swapping two characters at a time
    {
        temp = str[ind];
        str[ind] = str[len - ind - 1];      //swapping 1st with last, 2nd with 2nd last till len/2
        str[len - ind - 1] = temp;
        reverse_recursive(str, ind + 1, len);   //calling function recursively with next index
    }
}
