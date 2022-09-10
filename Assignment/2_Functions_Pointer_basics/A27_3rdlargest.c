/*
Name                    :   Deepika.S
Date                    :   27.07.2022
Description             :   Program to find 3rd largest element in an array
Sample execution        :   Enter the size of the Array : 5
                            Enter the elements into the array: 5 1 4 2 8
                            Third largest element of the array is 4
*/
#include <stdio.h>

int third_largest(int [], int);                    // function declaration

int main()
{
    int size, ret;                                //declaring variables
    printf("Enter the size of the array :");      //getting size and storing it
    scanf("%d", &size);

    int arr[size];                               //declaring array
    int iter;                                    //declaring variable for loop
    for(iter = 0; iter < size; iter++)
    {
      scanf("%d", &arr[iter]);                   //getting elements and storing it
    }

    ret = third_largest(arr, size);             //calling function and storing it at ret

    printf("Third largest element of the array is %d\n", ret);  //printing result
}
int third_largest(int arr[], int size)          //function definition
{
    int max1 = 0, max2 = 0, max3 =0;            //declaring max1, max2, max3 variables

    int iter;                 //declaring variable for loop
    for (iter = 0; iter < size; iter++)
    {
        if (max1 < arr[iter])                 //if max1 less than element then max3, max2 and max1 values are updated
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[iter];
        }
        else if ((max2 < arr[iter]) && (max1 > arr[iter]))  //else if element is greater then only max2 and max3 then max3 and max2 values are updated
        {
            max3 = max2;
            max2 = arr[iter];
        }
        else if ((max3 < arr[iter]) && (max2 > arr[iter]) && (max1 > arr[iter]))    //else if element is greater then only max3 then max3 is updated
        {
            max3 = arr[iter];
        }
    }
    return max3;                //max3 is returned to main function
}
