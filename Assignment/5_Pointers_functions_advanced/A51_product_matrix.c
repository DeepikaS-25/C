/*
Name                    :   Deepika.S
Date                    :   30.08.2022
Description             :   Program to find the product of given matrix
Sample execution        :   Enter number of rows : 3
                            Enter number of columns : 3
                            Enter values for 3 x 3 matrix :
                            1      2      3
                            1      2      3
                            1      2      3
                            Enter number of rows : 3
                            Enter number of columns : 3
                            Enter values for 3 x 3 matrix :
                            1      1     1
                            2      2     2
                            3      3     3
                            Product of two matrix :
                            14      14      14
                            14      14      14
                            14      14      14
*/

#include <stdio.h>
#include <stdlib.h>

int matrix_mul(int **, int, int, int **, int, int, int **, int, int);                  //function declaration

int main()
{
    int **mat_a, **mat_b, **result;                             //declaring matrix a, matrix b and result matrix
    int row1, row2, col1, col2, row_res, col_res, i, j;         //declaring row1 and col1 for matrix a and row2 and col2 for matrix b and row res and col res for result matrix and i and j for loop
    
    printf("Enter number of rows : ");                          //getting row and col for matrix a
    scanf("%d", &row1);
    printf("Enter number of columns : ");
    scanf("%d", &col1);
    mat_a = malloc(row1 * sizeof(int *));                       //dynamically allocating memory for row
    for(i = 0; i < row1; i++)
    {
        mat_a[i] = malloc(col1 * sizeof(int));                  //dynamically allocating memory for column
    }
    printf("Enter values for %d x %d matrix : \n", row1, col1);
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            scanf("%d", &mat_a[i][j]);                          //getting values of matrix a
        }
    }

    printf("Enter number of rows : ");                          //getting row and col for matrix b
    scanf("%d", &row2);
    printf("Enter number of columns : ");
    scanf("%d", &col2);
    mat_b = malloc(row2 * sizeof(int *));                       //dynamically allocating memory for row
    for(i = 0; i < row2; i++)
    {
        mat_b[i] = malloc(col2 * sizeof(int));                  //dynamically allocating memory for column
    }
    printf("Enter values for %d x %d matrix : \n", row2, col2);
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)                              //getting values of matrix b
        {
            scanf("%d", &mat_b[i][j]);
        }
    }
    
    if(col1 == row2)                                            //condition to check whether matrix multiplication is possible
    {
        row_res = row1;                                         //assigning row_res as row1
        col_res = col2;                                         //assigning col_res as col2
        result = malloc(row_res * sizeof(int *));               //dynamically allocating memory for row of result matrix
        for(i = 0; i < row_res; i++)
        {
            result[i] = malloc(col_res * sizeof(int));          //dynamically allocating memory for column of result matrix
        }
        matrix_mul(mat_a, row1, col1, mat_b, row2, col2, result, row_res, col_res);     //function call
    }
    else
    {
        printf("Matrix multiplication is not possible\n");      //prompting error when condition is not met
    }

    for (i = 0; i < row1; i++)
    {
        free(mat_a[i]);              //freeing dynamically allocated memory for columns of matrix a
    }
    for (i = 0; i < row2; i++)
    {
        free(mat_b[i]);              //freeing dynamically allocated memory for columns of matrix b
    }
    free(mat_a);
    free(mat_b);         //freeing dynamically allocated memory for rows of matrix a and b
    return 0;
}

int matrix_mul(int **mat_a, int row1, int col1, int **mat_b, int row2, int col2, int **result, int row_res, int col_res)    //function definition
{
    int i, j, k, sum = 0;                           //declaring i, j and k for loop and sum
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)                  //performing matrix multiplication by adding the products of row of matrix a and col of matrix b
        {
            for (k = 0; k < col1; k++)
            {
                sum = sum + (mat_a[i][k] * mat_b[k][j]);
            }
            result[i][j] = sum;       //storing obtained sum at result matrix
            sum = 0;                  //making sum as 0 for next loop of multplication
        }
    }
    printf("Product of two matrix :\n");        //printing the result(product of matrix a and b)
    for (i = 0; i < row_res; i++)
    {
        for(j = 0; j < col_res; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n\n");
    }
}
