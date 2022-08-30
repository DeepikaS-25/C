/*
Name                    :   Deepika.S
Date                    :   03.07.2022
Description             :   Program to generate AP, GP, HP series
Sample input            :   Enter the First Number 'A': 2
                            Enter the Common Difference / Ratio 'R': 3
                            Enter the number of terms 'N': 5
Sample output           :   AP = 2, 5, 8, 11, 14
                            GP = 2, 6, 18, 54, 162
                            HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428

*/

#include<stdio.h>
int main()
{
    int first, diff, n, next, prev;      //declaring variables for first element, difference or ratio no of elements and next
    int i, j, k;                         //declaring i,j,k for iterations for AP, GP and
    float last, nxt;                      //declaring float variables for HP

    printf("Enter the First Number 'A': ");
    scanf("%d", &first);                   //getting the first term

    printf("Enter the Common Difference / Ratio 'R': ");
    scanf("%d", &diff);                    //getting the difference or ratio

    printf("Enter the number of terms 'N': ");
    scanf("%d", &n);                       //getting the no of terms
    next = first;
    if (n > 0)                          //checking whether no of terms is valid or not
    {
        printf("AP = %d", first);
        for(i = 1; i < n; i++)                  //loop for AP
        {
            next = next + diff;                 //generating the elements by adding diff to previous elements
            printf(", %d", next);            //printing elements
        }
        prev = first;
        printf("\nGP = %d", first);
        for(j = 1; j < n; j++)                  //loop for GP
        {
            prev = prev * diff;                 //generating the elements by multiply diff with previous elements
            printf(", %d", prev);            //printing elements
        }
        nxt = first;
        printf("\nHP = %f", (1/nxt));
        for(k = 1; k < n; k++)                  //loop for HP
        {
            nxt = nxt + diff;
            last = 1 / nxt;                     //generating elements of HP
            printf(", %f", last);
        }
    }
    else                                  //if valid no of terms has not been passed then error has been prompted
    {
       printf("Invalid input");
    }
  return 0;
}
