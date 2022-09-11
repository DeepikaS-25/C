/*
Name                    :   Deepika.S
Date                    :   07.08.2022
Description             :   Program to implement strtok function
Sample execution        :   Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
                            Enter string2 : ;./-:
                            Tokens :
                            Bangalore
                            Chennai
                            Kolkata
                            Delhi
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);                  //function declaration

int main()
{
    char str[50], delim[50];                                    //declaring char array for string and delimiter

    printf("Enter the string  : ");                             //getting string from the user and storing it
    scanf("%s", str);

    __fpurge(stdin);                                           //flushing the buffer before getting another string

    printf("Enter the delimeter : ");                           //getting delimiter string from the user and storing it
    scanf("\n%s", delim);
    __fpurge(stdin);                                     

    char *token = my_strtok(str, delim);                        //function call with string only for the first time
    printf("Tokens :\n");

    while (token)                                               //calling function until returned position is null
    {
        printf("%s\n", token);                                 //printing tokens
        token = my_strtok(NULL, delim);                        //function call with NULL after first call
    }
}
char *my_strtok(char str[], const char delim[])             //function definition
{
     int j, start;                                          //declaring j for loop and start to hold starting address
     static int pos = 0;                                    //declaring static variable pos to hold where to begin the next search
     static char *ptr;                                      //static pointer to hold the string
     start = pos;                                           //assinging value in pos to start(as we need to print char from start)
     if(str != NULL)
     {
         ptr = str;                                         //assigning string to pointer
     }
     for (pos; ptr[pos] != '\0' ; pos++)                    //loop till element is null and incrementing each time to access next element of str
     {
        for(j = 0; delim[j] != '\0' ; j++)                  //loop till element is null and incrementing each time to access next element of delimiter
        {                                                   //checking whether element of string is one of the delimiter
            if(ptr[pos] == delim[j])                        //if element of the string is delimiter
            {
                ptr[pos] = '\0';                            //assigning it as null and incrementing pos to access next element
                pos = pos + 1;
                if (ptr[start] != '\0')                     //if starting element is not null then starting address of string is returned and token is printed till null
                {
                    return (&ptr[start]);
                }
                else                                        //if starting element is not null then assigning pos as starting for next loop
                {
                    start = pos;                            //assinging value in pos to start(as we need to print char from start)
                    pos--;                                  //decrementing position to continue from previous position
                    break;                                  //breaking the loop
                }
            }
        }
     }
     ptr[pos] = '\0';                                   //after completing all the elements ending string with null
     
     if (ptr[start] != '\0')                            //if start is not null
     {
         return (&ptr[start]);                            //returning start address to print token till null
     }

}
