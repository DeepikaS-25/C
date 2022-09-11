/*
Name                    :   Deepika.S
Date                    :   01.08.2022
Description             :   Program to implement atoi function
Sample execution        :   Enter a numeric string: 12345abcd
                            String to integer is 12345
*/

#include <stdio.h>

int my_atoi(const char []);      //function declaration

int main()
{
    char str[20];               //declaring string of size 20

    printf("Enter a numeric string : ");       //getting string and storing it
    scanf("%s", str);
    printf("String to integer is %d\n", my_atoi(str));  //printing integer by calling my_atoi function
}

int my_atoi(const char *str)        //function definition
{
    int len, i, no = 0, num;         //declaring variables len for string length, i for loop, no to hold number and num a temp variable
    for(len = 0; str[len] != '\0'; ++len);      //finding length of the string
    for(i = 0; i <= len; i++)        //loop for length times
    {
        if(((str[i] == 45) || (str[i] == 43)) && (i == 0))          //skipping when first char is + or -
        {
            continue;
        }
        if (str[i] >= 48 && str[i] <= 57 )           //when within range of 0 to 9 converting as integer
        {
            num = (no * 10);                        //multiplying prev number by 10
            no = num + (str[i] - 48);              //adding num with integer that has been converted from char
        }
        else
        {
            break;                          //breaking the loop if some other char
        }
    }
    no = (str[0] == 45) ? -no : no;        //if first char is - then negative no is returned
    return no;
}
