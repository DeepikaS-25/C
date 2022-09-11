/*
Name                    :   Deepika.S
Date                    :   10.08.2022
Description             :   Program to generate consecutive NRPS of length n using k distinct character
Sample execution        :   Enter the number characters C : 3
                            Enter the Length of the string N : 6
                            Enter 3 distinct characters : a b c
                            Possible NRPS is abcbca
*/

#include <stdio.h>

void nrps(char [], int, int);                   //function declaration

int main()
{

    int N, C, i;                                 //declaring variables n length of string, c no of characters and i for loop
    printf("Enter the number characters C : ");   //reading no of characters from the user
    scanf("%d", &C);

    printf("Enter the Length of the string N : "); //reading length of string from the user
    scanf("%d", &N);

    char str[N + 1];                               //creating array of size [N + 1] as we have to add null char at the end
    printf("Enter %d distinct characters : ", C);
    for(i = 0; i < C; i++)                         //reading chars from the user
    {
        scanf("\n%c", &str[i]);
    }
    int j;                                         //declaring j for loop
    for (i = 0; i < C; i++)                 //loop to check if all characters are distinct
    {
        for (j = i + 1; j < C; j++)
        {
            if(str[i] == str[j])
            {
                printf("Error: values are not distinct.\n");       //if not distinct prompting error
            }
        }
    }

    nrps(str, N, C);                    //function call with string, length and characters
    return 0;
}
void nrps(char str[], int N, int C)     //function definition
{
    int i, count = 0;                   //declaring count and loop variable
                       //not modifying previous part of string
    for (i = C; i < N; i++)               //loop till length of string is N
    {
        if (i % C == 0)         //incrementing count for every block of C(number of distinct) characters
		{
			count++;
		}
       str[i] = *(str + ((i + count) % C));  //generating nrps by assinging distinct chars for each block of C(number of distinct) characters
    }

    str[i] = '\0';             //adding null at the end to mark the end of string
    printf("Possible NRPS is %s", str);   //printing string

}
