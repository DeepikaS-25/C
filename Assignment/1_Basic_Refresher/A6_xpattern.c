/*
Name                    :   Deepika.S
Date                    :   07.07.2022
Description             :   Program to print the numbers in X format
Sample input            :   Enter the number: 4
Sample output           :   1  4
                             23
                             23
                            1  4
*/

#include <stdio.h>

int main()
{
    int num, row, col;           //declaring num as the number and row and columns as loop variables

    printf("Enter the number: ");
    scanf("%d", &num);              //getting number and storing it in num
    
    for (row = 1; row <= num; row++)    //loop for row
    {
        for (col = 1; col <= num; col++)           //loop for column
        {
            if ((row == col) || (row + col == num + 1) )    //condition to print numbers in x pattern
            {
                printf("%d", col);    //printing numbers
            }
            else
            {
                printf(" ");            //printing spaces in other places
            }
        }
        printf("\n");
    }
    return 0;
}
