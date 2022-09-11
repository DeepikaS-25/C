/*
Name                    :   Deepika.S
Date                    :   07.08.2022
Description             :   Program to squeeze the character in s1 that matches any character in the string s2
Sample execution        :   Enter string1 : Dennis Ritchie
                            Enter string2 : Linux
                            After squeeze s1 : Des Rtche
*/

#include <stdio.h>
#include <stdio_ext.h>

void squeeze(char [], char []);                    //function declaration

int main()
{
    char str1[30], str2[30];                       //declaring two strings

    printf("Enter string1:");                       //getting string 1
    scanf("%[^\n]", str1);

    __fpurge(stdin);                                //flushing buffer getting another string
    printf("Enter string2:");                      //getting string 2
    scanf("%[^\n]", str2);

    squeeze(str1, str2);                           //function call with string1 and string2

    printf("After squeeze s1 : %s\n", str1);       //printing string after squeezing

}
void squeeze(char str1[], char str2[])          //function not returning anything but modifying the string1
{
    int i, j;                                   //declaring variable i and j for loop
    static int pos = 0;                         //declaring static variable pos to hold the position of the modified string
    for(i = 0; str1[i] != '\0'; i++)             //loop till last character
    {
        int count = 0;                          //count variable to update only if element from string1 matches with string
        for(j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])             //checking whether element of string1 matches with any of the elements of string2
            {
                count++;
            }
        }
        if(count == 0)                          //if char was not in the string2 then that char is stored in string of position pos
        {
            str1[pos] = str1[i];
            pos++;                              //incrementing pos to store char next time
        }
    }
    str1[pos] = '\0';                           //after all the characters are compared then ending the modified string with null
}
