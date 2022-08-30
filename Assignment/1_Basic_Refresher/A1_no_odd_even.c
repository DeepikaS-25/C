/*
Name                    :   Deepika.S
Date                    :   30.06.2022
Description             :   Program to check if number is odd or even
Sample input            :   Enter the value of 'n' : -2
Sample output           :   -2 is negative even number
*/

#include <stdio.h>

int main()
{
    int n, mod;                                  //declaring n(number) and mod(modulus of number)
    printf("Enter the value of 'n' : ");         //getting no to check odd or even
    scanf("%d", &n);                             //storing the number in n
    if (n == 0)
    {
         printf("%d is neither odd nor even", n);     //printing 0 is neither even nor odd
    }
    else
    {
        mod = n % 2;                           //finding modulus of 2 for given num and assigning it to mod
        if (mod == 0)            //condition for even num that mod of 2 should be 0
        {
            if (n > 0)                          //condition for positive even num
            {
                printf("%d is positive even number",n);  //printing output
            }
            else                               //negative even
            {
                printf("%d is negative even number",n);
            }
        }                            
        else if (mod != 0)                  //condition for odd num that mod of 2 should not be 0
        {
            if (n > 0)                       //condition for positive odd num
            {
                printf("%d is positive odd number",n);
            }
            else                              //negative odd
            {
                printf("%d is negative odd number",n);
            }
        }  
    }    
    return 0;
}
