/*
Name                    :   Deepika.S
Date                    :   27.07.2022
Description             :   Program to find 2nd largest element in an array
Sample execution        :   Enter the size of the Array : 5
                            Enter the elements into the array: 5 1 4 2 8
                            Second largest element of the array is 5
*/

#include <stdio.h>

int sec_largest(int [], int);           // function declaration

int main()
{
    int size, ret;                      //declaring variables
    int iter;                           //declaring variable for loop

    printf("Enter the size of the array :");   //getting size and storing it
    scanf("%d", &size);

    int arr[size];                  //declaring array

    for(iter = 0; iter < size; iter++)        //getting elements and storing it
    {
      scanf("%d", &arr[iter]);
    }

    ret = sec_largest(arr, size);             //calling function and storing it at ret

    printf("Second largest element of the array is %d\n", ret);     //printing result
}

int sec_largest(int arr[], int size)        //function definition
{
    int sec_large = 0, fst_large = 0;       //declaring first and second large variables
    int iter;                               //declaring loop variable for loop
    for (iter = 0; iter < size; iter++)
    {
        if(fst_large < arr[iter])           //condition to find 2nd largest element
        {
            sec_large = fst_large;          //if first large is less than element then first large and second large values are updated
            fst_large = arr[iter];
        }

        else if (sec_large < arr[iter])     //else if only second large value is less than element then second large is updated
        {
            sec_large = arr[iter];
        }
    }
    
    return sec_large;           //returning second large to the main function

}
