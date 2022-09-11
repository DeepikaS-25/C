/*
Name                    :   Deepika.S
Date                    :   15.08.2022
Description             :   Program to calculate variance using dynamic arrays
Sample execution        :   Enter the no.of elements : 10

                            Enter the 10 elements:
                            [0] -> 9
                            [1] -> 12
                            [2] -> 15
                            [3] -> 18
                            [4] -> 20
                            [5] -> 22
                            [6] -> 23
                            [7] -> 24
                            [8] -> 26
                            [9] -> 31
                            Variance is 40.000000
*/

#include <stdio.h>
#include <stdlib.h>

float variance(int *, int);                     //function declaration

int main()
{
    int size, i;                                //declaring size and i for loop
    float var;
    printf("Enter the no.of elements: ");
    scanf("%d", &size);                         //reading size from the user
    printf("\nEnter the %d elements:\n", size);
    int *arr;                                   //declaring a pointer to array
    arr = (int *)malloc(size * sizeof(int));    //allocating memory for array
    
    for(i = 0; i < size; i++)
    {
        printf("[%d] -> ", i);                  //reading elements of the array
        scanf("%d", &arr[i]);
    }
    var = variance(arr, size);                  //function call with array and its size to find variance of the array
    
    printf("variance is %f", var);              //printing variance
    free(arr);                                  //freeing allocated memory of the array
    arr = NULL;                                 //pointing array to NULL
    return 0;
}
float variance(int *arr, int size)              //function definition
{
    int mean, sum = 0, i;                       //declaring mean, i for loop and sum as 0
    for(i = 0; i < size; i++)
    {
        sum = sum + arr[i];                     //loop to find sum of elements of the array
    }
    mean = (float) sum / size;                  //finding mean
    int *Dev, *Dev_sqr;                    //declaring 2 pointers Dev for finding deviaton and Dev_sqr for finding deviation square
    Dev = (int *)malloc(size * sizeof(int));    //allocating memory for array
    Dev_sqr = (int *)malloc(size * sizeof(int));    //allocating memory for array
    for(i = 0; i < size; i++)
    {
        Dev[i] = arr[i] - mean;                 //finding deviation
        Dev_sqr[i] = Dev[i] * Dev[i];               //finding deviation square
    }
    sum = 0;
    for(i = 0; i < size; i++)
    {
       sum = sum + Dev_sqr[i];                  //finding sum of all elements of array Deviation square
    }
    float var;                                  //declaring a float variable for variance
    var = (float) sum / size;                   //finding variance

    free(Dev);                                  //freeing allocated heap memory of Deviation array
    free(Dev_sqr);                              //freeing allocated heap memory of Deviation square array
    Dev = NULL;                                 //pointing array to NULL
    Dev_sqr = NULL;

    return var;                    //returning variance to function call
}
