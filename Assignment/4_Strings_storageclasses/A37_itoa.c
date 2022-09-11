/*
Name                    :   Deepika.S
Date                    :   02.08.2022
Description             :   Program to implement itoa function
Sample execution        :   Enter a numeric string: -12345
                            String to integer is -12345
*/

#include <stdio.h>

int itoa(int num, char str[]);      //function declaration

int main()
{
    int num, ret;                 //declaring num to hold number
    char str[10];                 //declaring string of size 20

    //printf("Enter a number: ");   //getting number and storing it
    ret = scanf("%d", &num);      //checking whether valid integer is entered or not
    if (ret != 1)
    {
        num = 0;                 //if not making num as 0
    }
    itoa(num, str);         //function call
    printf("Integer to string is %s", str);  //printing string by calling itoa function
}

int itoa(int num,char *str)        //function definition
{
    int len, temp, i = 0, org_num;         //declaring variables len for string length, i for loop and temp a temporary variable
    org_num = num;                        //org_num holds number

    if(num == 0)
    {
        str[0] = 48;                    //if num is 0 then making a string with char 0
        str[1] = '\0';                  //adding null char at the end
    }
    else
    {
        if(num < 0)
        {
            num = - num;            //if number is negative changing it as positive
        }
        while(num != 0)     //loop which converts num into string of characters
        {
            str[i] = (num % 10) + 48;   // converting each integer digit by digit to characters and storing it in string
            num = num / 10;             //to access next digit dividing by 10
            i++;                        //incrementing index each time
        }
        str[i] = '\0';                 // ending string with null

        for(len = 0; str[len] != '\0'; ++len);        //finding length of the string
        //reversing the string since we got num in reversed order

        for(i = 0; i < len/2; i++)          //loop to swap the elements till len/2 times since we are swapping two characters at a time
        {
            temp = str[i];                  //temp variable to store the char
            str[i] = str[len - i - 1];      //swapping 1st with last, 2nd with 2nd last till len/2
            str[len - i - 1] = temp;
        }
        if(org_num < 0)     //when num is negative adding first character as -(minus) symbol
        {
            for(i = len + 1; i > 0; --i)          //loop to swap the elements
            {
                str[i] = str [i - 1];         //each character is shifted right once
            }
            str[0] = 45;                //first character as -(minus) symbol
       }
    }
}
