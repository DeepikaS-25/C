/*
Name                    :   Deepika.S
Date                    :   07.08.2022
Description             :   Program to check given string is Pangram or not
Sample execution        :   Enter the string: The quick brown fox jumps over the lazy dog

                            The Entered String is a Pangram String
*/
#include <stdio.h>

int pangram(char str[]);                    //function declaration

int main()
{
    char str[100];                          //declaring char string

    printf("Enter the string:");            //getting string and storing it
    scanf("%[^\n]", str);
    
    pangram(str);                           //function call with string
    return 0;


}
int pangram(char str[])                     //function definition
{
    int i;                                  //declaring i for loop
    static int count = 0;                   //declaring static variable count to hold the count
    char arr[26] = {0};                     //creating an array of 0 with 26 as size
    for(i = 0; str[i] != '\0'; i++)         //running loop till last element
    {
        if(str[i] >= 'A'&& str[i] <= 'Z')      //condition to check element is within the range of capital alphabets
        {
            arr[str[i] - 'A']= 1;               //if found then updating the presence of that alphabet in its place of array as 1
        }
        else if(str[i] >= 'a' && str[i] <= 'z')    //condition to check element is within the range of lower case alphabets
        {
            arr[str[i] - 'a'] = 1;             //if found then updating the presence of that alphabet in its place of array as 1
        }
    }
    for(i = 0; i < 26; i++)             //loop to check if all the elements are 1(all the alphabets are present)
    {
         if (arr[i] == 1)               //incrementing count if array element is 1
         {
            count++;
         }
    }
                //if all the alphabets are present then printing result
    count == 26 ? printf("\nThe Entered String is a Pangram String") : printf("\nThe Entered String is not a Pangram String");
}
