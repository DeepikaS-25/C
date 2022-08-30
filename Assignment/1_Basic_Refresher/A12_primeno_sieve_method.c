/*
Name                    :   Deepika.S
Date                    :   13.07.2022
Description             :   Program to print all primes using Sieve of Eratosthenes method
Sample input            :   Enter the value of 'n' : 20
Sample output           :   The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
*/


#include <stdio.h>
int main()
{
    int num, sqrt = 1;                          //declaring num for value and initializing sqrt to find square root
    int iter, loop, count = 0;                              //declaring iter and loop for loop variables
    //printf("Enter the value of 'n' : ");
    scanf("%d", &num);                          //getting num from the user

    if (num <= 1)                               //condition to check whether entered num is greater than 1
    {
        printf("Please enter a positive number which is > 1");
    }
    else
    {
        int array[num];                          //declaring array of size num
        for( iter = 0; iter <= num + 1; iter++)  //finding square root using loop
        {
            sqrt = (num / sqrt + sqrt) / 2;
        }
       
        for(loop = 0; loop <= num - 2; loop++)   //storing elements in the array using loop
        {
            array[loop] = loop + 2;
        }
        printf("The primes less than or equal to %d are : ", num);
        for(iter = 0; iter < num - 1; iter++)       //loop giving elements of the array one by one
        {
            for(loop = 2; loop <= sqrt; loop++)   //loop giving elements less than value of square root
            {  
                if (array[iter] == loop)         //if the element is same as sqrt then leaving that element as it is
                {
                    array[iter] = loop;
                }
                else if (array[iter] % loop == 0 ) //if element divisible by loop value then replacing it with 0
                {
                    array[iter] = 0;
                }   
            }
            if (array[iter] != 0)
            {
                if (count != 0)
                {
                    printf(", "); 
                }
                printf("%d", array[iter]);
                count++;
            }    
        } 
    }
    return 0;
}