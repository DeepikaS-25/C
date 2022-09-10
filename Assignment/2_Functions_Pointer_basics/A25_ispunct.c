/*
Name                    :   Deepika.S
Date                    :   22.07.2022
Description             :   Program to implement own my_ispunct() function
Sample execution        :   Enter the character: a
                            Entered character is not punctuation character
*/#include <stdio.h>

int my_ispunct(int);                        //function declaration

int main()
{
    char ch;                                //declaring variables
    int ret;

    //printf("Enter the character:");       //getting character and storing it
    scanf("%c", &ch);

    ret = my_ispunct(ch);                   //calling my_ispunct function with ch argument
                                            //using ternary operator to print output if ch is returned
    (ret != 0) ? printf("Entered character is punctuation character") : printf("Entered character is not punctuation character");

}

int my_ispunct(int ch)                     //function definition
{
    if(((ch >= '!') && (ch <= '/')) || ((ch >= ':') && (ch <= '@')) || ((ch >= '[') && (ch <= '`')) || ((ch >= '{') && (ch <= '~')))         //range of punctuation characters
    {
        return ch;                         //returning ch
    }
    else
    {
        return 0;                          //else returning 0
    }
}
