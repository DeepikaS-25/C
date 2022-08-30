/*
Name                    :   Deepika.S
Date                    :   08.07.2022
Description             :   Program to print pyramid pattern as given
Sample input            :   Enter the number: 4

Sample output           :   4
                            3 4
                            2 3 4
                            1 2 3 4
                            2 3 4
                            3 4
                            4
*/

#include <stdio.h>
int main()
{
    int num, row, column;               //declaring number, row and column
    printf("Enter the number: ");
    scanf("%d", &num);                 //getting number from user and storing it
    for (row = 1; row <= num; row++)   //loop for row
    {
        for (column = 0; column <= num; column++)  //loop for column
        {
            if (row > column)              //condition for first half of pyramid
            {
                printf("%d ", column + num - row + 1); //printing elements
            }
        }
        printf("\n");                     //new line after each row
    }
    for (row = 1; row <= num; row++)    //second half pyramid loop for row
    {
        for (column = 1; column <= num; column++) //loop for column
        {
            if (row < column)             //condition for second half pyramid
            {
                printf("%d ", column);       //printing elements
            }
        }
        printf("\n");                     //new line after each row
    }
    return 0;
}

