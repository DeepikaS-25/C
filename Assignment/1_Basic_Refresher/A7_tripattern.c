/*
Name                    :   Deepika.S
Date                    :   07.07.2022
Description             :   Program to print triangle pattern
Sample input            :   Enter the number: 4
Sample output           :   1 2 3 4
                            5   6
                            7 8
                            9
*/

#include<stdio.h>

int main()
{
   int num, row, col;               //declaring number of rows to print as num and row and column for rows and columns
   int count = 1,first;                  //initializing count as 1 to print numbers

   printf("Enter the number: ");
   scanf("%d", &num);                   //getting number and storing it
   for(row = 1; row <= num; row++)     //loop for row
   {
      for (col = num - row; col >= 0; col--)   //loop for column
      {
         if (row == 1 || col == 0 || (col == num - row))              //printing column no of elements for only the first row
         {
            printf("%d ",count);       //printing elements
            count++;         //incrementing count after each element is printed
         }
         else
         {
            printf("  ");
         }     
      }
      printf("\n");                  //printing new line after each row
   }
  return 0;
}
