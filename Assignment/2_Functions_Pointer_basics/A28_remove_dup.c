/*
Name                    :   Deepika.S
Date                    :   25.07.2022
Description             :   Program to remove duplicate elements in a given array
Sample execution        :   Enter the size: 5

                            Enter elements into the array: 5 1 3 1 5

                            After removing duplicates: 5 1 3
*/

#include <stdio.h>

void fun(int arr1[], int size, int arr2[], int *new_size);      //function declaration

int main()
{
    int size, iter;                                             //declaring variables for size(of array) and iter(for loop)
    printf("Enter the size: ");                                 //getting size and storing it
    scanf("%d", &size);
    
    int arr1[size];                                             //initialising array of size
    int arr2[size];                                             //initialising another array of size (size)
    int *new_size = &size;                                      //creating a pointer to hold address of array of non-duplicate elements
    
    printf("\nEnter elements into the array: ");                //prompting to enter elements
    for(iter = 0; iter < size; iter++)
    {
      scanf("%d", &arr1[iter]);                                 //getting elements and storing it
    }
    
    fun(arr1, size, arr2, new_size);                            //function call 
    
    printf("\nAfter removing duplicates: ");
    for(iter = 0; iter < *new_size ; iter++)                    //printing array after deleting duplicate elements
    {
      printf("%d ", arr2[iter]);
    }


}

void fun(int arr1[], int size, int arr2[], int *new_size)       //function definition
{
    arr2[0] = arr1[0];                                          //copying first number of the array1 to arrray2
    
    int i, j, org_num = 1;                                      //declaring variables i and j for loops and org_num for no.of non-duplicate numbers
    
    for(i = 1; i < size; i++)                                   //outer loop to give numbers from 1 to size
    {
        int count = 1;                                          //count holds the number of elements compared each time in inner loop
        for(j = 0; j < org_num; j++)                            //inner loop to compare array1 elements with array2 elements which holds only unique elements
        {
            if(arr1[i] == arr2[j])                              //if numbers are same then breaking the loop
            {
               break;
            }
            else if((arr1[i] != arr2[j]) && (org_num == count))  //if numbers are unique and compared with all elements of array2
            {
              arr2[j + 1] = arr1[i];                            //adding element to array2
              org_num++;                                        //after adding incrementing org_num
            }
            count++;                                             //incrementing count after each comparison
        }
    }
    
   *new_size = org_num;                                         //pointer holding the value of original number of elements

}
