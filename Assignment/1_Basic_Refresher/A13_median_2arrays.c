/*
Name                    :   Deepika.S
Date                    :   13.07.2022
Description             :   Program to find the median of two unsorted arrays
Sample execution        :   Enter the 'n' value for Array A: 5
                            Enter the 'n' value for Array B: 4
                            Enter the elements one by one for Array A: 3 2 8 5 4
                            Enter the elements one by one for Array B: 12 13 7 5
                            Median of array1 : 4
                            Median of array2 : 9.5
                            Median of both arrays : 6.75

*/


#include<stdio.h>
int main()
{
    int count1, count2;                 //count1 and count2 are size of arrays a and b
    int temp, mid;                      //temp for sorting arrays and mid to hold int value of index of array
    int  iter, loop;                    //variables for loop
    float mid1, mid2, median;           //medians of array A and B and median holds median value of two medians of arrays

    printf("Enter the 'n' value for Array A: ");    //getting size of array A
    scanf("%d", &count1);
    printf("Enter the 'n' value for Array B: ");    //getting size of array B
    scanf("%d", &count2);

    int arr_a[count1];                              //declaring array A of size count1
    int arr_b[count2];                              //declaring array B of size count2

    printf("Enter the elements one by one for Array A: ");
    for(iter = 0; iter < count1; iter++)            //getting elements of array A from the user
    {
        scanf("%d", &arr_a[iter] );
    }

    printf("Enter the elements one by one for Array B: ");
    for(loop = 0; loop < count2; loop++)            //getting elements of array B from the user
    {
        scanf("%d", &arr_b[loop] );
    }

    for(iter = 0; iter < count1; iter++ )          //loop to give elements of array A one by one
    {
        for(loop = 0; loop < (count1 - 1); loop++) //loop to sort array elements
        {
           if ( arr_a[loop] > arr_a[loop + 1] )
            {
               temp = arr_a[loop];                 //swapping elements if condition is true
               arr_a[loop] = arr_a[loop + 1];
               arr_a[loop + 1] = temp;
            }
        }
    }

    for(iter = 0; iter < count2; iter++)          //loop to give elements of array B one by one
    {
        for(loop = 0; loop < (count2 - 1); loop++) //loop to sort array elements
        {
            if ( arr_b[loop + 1] < arr_b[loop] )
            {
               temp = arr_b[loop];                 //swapping elements if condition is true
               arr_b[loop] = arr_b[loop + 1];
               arr_b[loop + 1] = temp;
            }
        }
    }

    if (count1 % 2)                               //if count1 is odd setting mid as mid element
    {
        mid = count1 / 2;
        mid1 = arr_a[mid];
    }
    else                                           //if count1 is even then finding median of mid 2 array elements
    {
        mid = count1 / 2;                          //storing mid as integer since index should be integer
        mid1 = (float) (arr_a[mid] + arr_a[mid - 1]) / 2;  //typecasting int to float since median can be float
    }

    if (count2 % 2)                               //if count2 is odd setting mid as mid element
    {
        mid = count2 / 2;
        mid2 = arr_b[mid];
    }
    else                                           //if count2 is even then finding median of mid 2 array elements
    {
        mid = count2 / 2;                          //storing mid as integer since index should be integer
        mid2 = (float) (arr_b[mid] + arr_b[mid - 1]) / 2;  //typecasting int to float since median can be float
    }

    printf("Median of array1 : %g \nMedian of array2 : %g\n", mid1, mid2);
    median = (mid1 + mid2) / 2;                    //finding median of medians of two array elements
    printf ("Median of both arrays : %g", median);
    return 0;
}
