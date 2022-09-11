/*
Name                    :   Deepika.S
Date                    :   31.07.2022
Description             :   Program to implement getword function
Sample execution        :   Enter the string : Hello
                            You entered Hello and the length is 5
*/
#include <stdio.h>

int getword(char str[]);                    //function declaration

int main()
{
        int len;                    //declaring length
	    char str[100];              //initializing str with size 100

		//printf("Enter the string : ");
		scanf(" %[^\n]", str);      //getting string from the user

		len = getword(str);         //function call

        printf("You entered %s and the length is %d\n", str, len);  //printing output
}

int getword(char *str)              //function definition
{
    int len = 0;                    //initializing length with 0
    while(*str != ' ')              //counting till space
    {
        len++;                      //incrementing count
        str++;                      //incrementing str ptr to access next char
        if(*str == '\0')            //if null then breaking loop
        {
            break;
        }
    }
    *str = '\0';                //adding null at end after space or null
    return len;                 //returning length
}
