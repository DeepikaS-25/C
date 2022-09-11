/*
Name                    :   Deepika.S
Date                    :   30.08.2022
Description             :   Program to generate a n*n magic square
Sample execution        :   Enter a number: 3
                            8      1      6
                            3      5      7
                            4      9      2
*/

#include <stdio.h>
#include <stdlib.h>

void magic_square(int **, int);     //function declaration

int main()
{
    int tot_row;
    //printf("Enter a number: ");                      //getting total no. of rows from the user and storing it as tot_row
    scanf("%d", &tot_row);

    if (((tot_row % 2) == 0) || (tot_row < 0))       //condition to check whether the entered no is positive and odd
    {
        printf("Error : Please enter only positive odd numbers");      //prompting error if no is not positive odd number
    }
    else
    {
        int **arr;
        magic_square(arr, tot_row);                 //calling function with 2d array and row
    }
    return 0;
}

void magic_square(int **arr, int tot_row)           //function definition
{
    int col, num, row = 0;
    arr = calloc(tot_row, sizeof(int *));           //allocating memory dynamically for rows

    for (col = 0; col < tot_row; col++)
    {
        arr[col] = calloc(tot_row, sizeof(int));     //allocating memory dynamically for columns
    }
    col = tot_row / 2;                               //to start from the middle of the row
    for (num = 1; num <= (tot_row * tot_row); ++num)      //loop to run till (3x3) 9 
    {
        arr[row][col] = num;                        //adding element
        row--;                                      //moving one row upwards
        col++;                                      //moving one column rightwards
        if(num % tot_row == 0)                      //when position is already filled
        {
            row = row + 2;                          //moving one row down (as we updated row and column(while adding element) compensating that by subtracting 2 from row and 1 from column)
            col = col - 1;
        }
        else
        {
            if (col == tot_row)                     //when last column reached moving to first column
            {
                col = col - tot_row;
            }
            else if (row < 0)                       //when row less than 0 i.e, no row exist before
            {
                row = row + tot_row;                //moving to last row
            }
        }
    }
    for (row = 0; row < tot_row; row++)         //printing magic square
    {
        for (col = 0; col < tot_row; col++)
        {
            printf("%d  ", arr[row][col]);
        }
        printf("\n\n");
    }
    for (col = 0; col < tot_row; col++)
    {
        free(arr[col]);         //freeing dynamically allocated memory(for columns)
    }
    free(arr);                  //freeing dynamically allocated memory(for rows)
}
