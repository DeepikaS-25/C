/*
Name                    :   Deepika.S
Date                    :   26.08.2022
Description             :   Program to implement fragments using Array of Pointers
Sample execution        :   Enter no.of rows : 3
                            Enter no of columns in row[0] : 4
                            Enter no of columns in row[1] : 3
                            Enter no of columns in row[2] : 5
                            Enter 4 values for row[0] : 1 2 3 4
                            Enter 3 values for row[1] : 2 5 9
                            Enter 5 values for row[2] : 1 3 2 4 1

                            Before sorting output is:

                            1.000000 2.000000 3.000000 4.000000 2.500000

                            2.000000 5.000000 9.000000 5.333333

                            1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

                            After sorting output is:

                            1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

                            1.000000 2.000000 3.000000 4.000000 2.500000

                            2.000000 5.000000 9.000000 5.333333

*/

#include <stdio.h>
#include <stdlib.h>

int fragments(int, float *[]);                      //function declaration for implementing fragments
int print_array(int, int [], float *[]);            //function declaration for printing array

int main()
{
    int row;                                       //defining row
    printf("Enter no. of rows : ");                //getting row from the user
    scanf("%d", &row);
    float *ptr_array[row];                          //declaring a first static second dynamic 2d arrray
    fragments(row, ptr_array);                      //function call with row and 2d array
    return 0;
}

int fragments(int row, float *ptr_array[])         //function definiton
{
    int arr[row], i, j;                             //declaring an integer array to hold number of elements in each column
    for(i = 0; i < row; i++)                        //getting no of columns in each row
    {
        printf("Enter no of columns in row[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < row; i++)                        //getting elements of each column for a given row and finding average of the elements
    {
        fflush(stdin);
        ptr_array[i] = malloc((arr[i] + 1) * sizeof(float));        //dynamically allocating memory with one extra block for average for each row
        float sum = 0, average = 0;
        printf("Enter %d values for row[%d] :",arr[i], i);          //getting values of column
        for(j = 0; j < arr[i]; j++)
        {
            scanf("%f", &ptr_array[i][j]);
            sum = sum + ptr_array[i][j];                            //finding sum each time
        }
        average = sum / arr[i];                                     //at the end of each row, finding average and updating it at the end of each row
        ptr_array[i][j] = average;
    }

    printf("\nBefore sorting output is:\n\n");
    print_array(row, arr, ptr_array);                               //printing array before swapping
    float *temp, swap;                                              //declaring a temporary pointer and variable swap to implement fragments
    //sorting and swapping
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < row - 1; j++)                               //sorting till second last row so (row - 1)
        {
            if (ptr_array[j][arr[j]] > ptr_array[j + 1][arr[j + 1]])    //checking whether last element of a row is greater than last element of next row
            {
                temp = ptr_array[j];                                //sorting array if condition is true using temp array
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = temp;

                swap = arr[j];                                      //sorting elements of integer array using temp swap
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
    printf("\nAfter sorting output is:\n\n");
    print_array(row, arr, ptr_array);                               //printing array after sorting

    for (i = 0; i < row; i++)
    {
        free(ptr_array[i]);                                         //freeing pointer and pointing to NULL to avoid dangling pointers
    }
    ptr_array = NULL;
}

int print_array(int row, int arr[row], float *ptr_array[])          //function definition for printing array elements
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j <= arr[i]; j++)
        {
           printf("%f ", ptr_array[i][j]);                      //printing elements of 2D array
        }
        printf("\n\n");
    }
}
