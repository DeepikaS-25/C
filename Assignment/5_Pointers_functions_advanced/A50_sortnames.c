/*
Name                    :   Deepika.S
Date                    :   30.08.2022
Description             :   Program to read n person names and print the names in sorted order
Sample execution        :   Enter the size: 5

                            Enter the 5 names of length max 20 characters in each
                            [0] -> Delhi
                            [1] -> Agra
                            [2] -> Kolkata
                            [3] -> Bengaluru
                            [4] -> Chennai

                            The sorted names are:
                            Agra
                            Bengaluru
                            Chennai
                            Delhi
                            Kolkata
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void sort_names(char (*)[20], int);                 //function declaration to sort names
int my_strcmp(const char *, const char *);          //declaration of string compare function
void my_strcpy( char *, const char *);              //declaration of string copy function

int main()
{
    int rows, i;                                //declaring rows as no of names to be sorted
    char (*names)[20];                          //declaring an array with constant length(column) and dynamic rows
    printf("Enter the size: ");                 //getting rows from the user
    scanf("%d", &rows);
    names = malloc(rows * sizeof(*names));      //dynamically allocating memory for rows
    printf("\nEnter the %d names of length max 20 characters in each \n", rows);
    for(i = 0; i < rows; i++)                   //getting names from the user
    {
       __fpurge(stdin);
       printf("[%d] -> ", i);
       scanf("%20[^\n]", names[i]);
    }

    sort_names(names, rows);                   //function call with names array and rows

    free(names);                               //freeing dynamically allocated memory
    names = NULL;
    return 0;
}

void sort_names(char (*names)[20], int rows)       //function definition for sorting names
{
    int i, j;                               //declaring i, j and k for loop
    char temp[20];                          //declaring a temporary string for swapping
    for(i = 0; i < rows - 1; i++)
    {                                       //sorting names by comparing characters of the names
        for (j = i + 1; j < rows; j++)
        {
            if (my_strcmp(names[i], names[j]) > 0)  //comparing strings using string compare function
            {
                my_strcpy(temp, names[j]);
                my_strcpy(names[j], names[i]);      //swapping the strings by string copy function
                my_strcpy(names[i], temp);
            }
        }
    }
    printf("\nThe sorted names are:\n");
    for (i = 0; i < rows; i++)              //printing the names in sorted order
    {
        fflush(stdout);
        printf("%s\n", names[i]);
    }
}


void my_strcpy(char *dest, const char *src)             //string copy function definition
{
    while(*src)
    {
        *dest++ = *src++;                   //copying character by character
    }
    *dest = '\0';                           //appending null at the end
}

int my_strcmp(const char *str1, const char *str2)       //string compare function definition
{
    while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2)     //comparing till null and same character
    {
        str1++;
        str2++;
    }
    return (*str1 - *str2);                            //returning difference when characters are unequal
}
