/*
Name                    :   Deepika.S
Date                    :   31.07.2022
Description             :   Program to print values of array in sorted order without modifying or copying array
Sample execution        :   Enter the size of the array : 4
                            Enter the 4 elements
                            -1 -2  4 3
                            After sorting: -2 -1 3 4
                            Original array values -1 -2  4 3
*/

#include <stdio.h>

void print_sort(int [], int);                   //function declaration

int main()
{
    int size, iter;                             //declaring variables

    printf("Enter the size of the array : ");   //getting size from the user and storing it
    scanf("%d", &size);

    int arr[size];                              //initializing array with size

    printf("Enter the %d elements\n",size);     //prompting to enter elements
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);                //getting array elements from the user
    }

    print_sort(arr, size);                      //function call
    printf("\nOriginal array values ");
    for (iter = 0; iter < size; iter++)
    {
        printf("%d ", arr[iter]);               //printing unmodified array
    }
}

void print_sort(int arr[], int size)            //function definition
{
    int large = arr[0], small = arr[0], small2, iter;   //declaring variables
    int count = 0;                              //variable for counting iteration
    for (iter = 0; iter < size; iter++)         //loop to find largest and smallest number
    {
        large = ((large < arr[iter]) ? arr[iter] : large);      //largest number
        small = ((small > arr[iter]) ? arr[iter] : small);      //smallest number
    }
    small2 = large;                             //variable small2 to hold 2nd smallest number initializing with large
    printf("After sorting: ");
    do
    {
        printf("%d ", small);                   //printing elements in sorted order
        for (iter = 0; iter < size; iter++)
        {
            if ((arr[iter] > small) && (arr[iter] < small2))    //condition to find the next smallest number
            {
                    small2 = arr[iter];         //assigning it to small2
            }
        }
        small = small2;             //next small stored in small
        small2 = large;             //small2 holds large
        count++;                    //counting to compare all the elements
    } while(count < size);          //do while loop to execute until condition is true
}
