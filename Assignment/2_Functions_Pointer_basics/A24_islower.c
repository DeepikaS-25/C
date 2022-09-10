/*
Name                    :   Deepika.S
Date                    :   22.07.2022
Description             :   Program to implement own my_islower() function
Sample execution        :   Enter the character: a
                            Entered character is lower case alphabet
*/
#include <stdio.h>

int my_islower(int);                    //function declaration

int main()
{
    char ch;                            //declaring variables
    int ret;

    //printf("Enter the character:");   //getting character and storing it
    scanf("%c", &ch);

    ret = my_islower(ch);               //calling  my_islower() function with ch argument
                                        //using ternary operator to print output if ch is returned
    (ret != 0) ? printf("Entered character is lower case alphabet") : printf("Entered character is not lower case alphabet");

}

int my_islower(int ch)
{
    if((ch >= 'a') && (ch <= 'z'))       //range of lowercase alphabets
    {
        return ch;                      //returning ch
    }
    else
    {
        return 0;                      //else returning 0
    }
}
