/*
Name                    :   Deepika.S
Date                    :   11.08.2022
Description             :   Program to print all possible combinations of given string.
Sample execution        :   Enter a string: abc

                            All possible combinations of given string :abc
                            acb
                            bca
                            bac
                            cab
                            cba
*/

#include<stdio.h>

void combination(char [],int ,int );            //function declaration for printing combinations
int my_strlen(char []);                        //function declaration for finding length of the string

int main()

{
    char str[100];                  //declaring a string array
    int n;                          //declaring n length of the string
    int res;
    printf("Enter a string: ");     //reading string from the user
    scanf("%100[^\n]",str);
    n = my_strlen(str);             //finding length of string using my_strlen function
    int j, i;                      //declaring i, j for loop
    for (i = 0; i < n; i++)                 //loop to check if all characters are distinct
    {
        for (j = i + 1; j < n; j++)
        {
            if(str[i] == str[j])
            {
                printf("Error: values are not distinct.\n");       //if not distinct prompting error
            }
        }
    }
    printf("\nAll possible combinations of given string : ");

    combination(str,0,n-1);       //function call with string start and end index
    return 0;
}

int my_strlen(char str[])        //function definition for calculating the string length
{
    int len;
    for (len = 0; str[len] != '\0'; len++);
    return len;        //returning length of the string
}

void combination(char str[], int start, int end)       //function definition for finding combinations of the string
{
    if (start == end)
    {
        printf("%s\n", str);            //printing combinations
    }
    else
    {
        int i;                      //declaring i for loop
        char temp;                  //declaring temp to swap the elements
        for(i = start; i <= end; i++)
        {
            temp = str[start];              //swapping characters
            str[start] = str[i];
            str[i] = temp;

            combination(str, start + 1, end);   //calling function recursively with next index each time
                                                    //hence all the combinations of the string can be achieved
            temp = str[start];             //swapping elements
            str[start] = str[i];
            str[i] = temp;
        }
    }
}
