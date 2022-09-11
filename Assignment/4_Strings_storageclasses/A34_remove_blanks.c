/*
Name                    :   Deepika.S
Date                    :   01.08.2022
Description             :   Program to replace each string of one or more blanks by a single blank
Sample execution        :   Pointers     are               sharp     knives.
                            Pointers are sharp knives.
*/

#include <stdio.h>
void replace_blank(char []);        //function declaration

int main()
{
    char str[100];                  //declaring string of size 30

    //printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);        //getting string from the user and storing it

    replace_blank(str);        //function call to replace blanks

    printf("%s\n", str);        //printing modified string that doesn't have extra spaces or tab
}

void replace_blank(char *str)        //function definition
{
    int i, len, j = 0;                 //declaring variables i for loop, len for length of string and j to count modified char count

    for(len = 0; str[len] != '\0'; ++len);      //finding length of the string

    for(i = 0; i < len; i++)        //loop for length times
    {
        if ((*(str+i) == ' ')  && (*(str + i + 1) == ' '))    //if more than one space is found skipping doing nothing
        {
        }
        else if ((*(str+i) == '\t') && (*(str + i + 1) == '\t'))  //if more than one tab is found skipping doing nothing
        {
        }
        else                          //else swapping other characters
        {
            str[j] = *(str + i);
            j++;
        }
    }
    str[j] = '\0';              //adding null character at the end to mark end of string
}
