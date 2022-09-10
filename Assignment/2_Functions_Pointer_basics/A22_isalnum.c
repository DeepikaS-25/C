/*
Name                    :   Deepika.S
Date                    :   22.07.2022
Description             :   Program to implement own isalnum() function
Sample execution        :   Enter the character: a
                            Entered character is alphanumeric character
*/


#include <stdio.h>

int my_isalnum(int);                    //function declaration

int main()
{
    char ch;                            //declaring variables
    int ret;

    //printf("Enter the character:");   //getting character and storing it
    scanf("%c", &ch);

    ret = my_isalnum(ch);               //calling my_isalnum function with ch argument
                                        //using ternary operator to print output if ch is returned
    (ret != 0) ? printf("Entered character is alphanumeric character") : printf("Entered character is not alphanumeric character");
}

int my_isalnum(int ch)                  //function definition (function returns ch only if entered is alphanumeric character) 
{
  if(((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) ||  ((ch >= '0') && (ch <= '9')))     //if lowercase,uppercase and decimal numbers
  {
     return ch;                         //returning ch
  }
  else
  {
     return 0;                          //else returning 0
  }
}

