/*
Name                    :   Deepika.S
Date                    :   17.07.2022
Description             :   Program to toggle 'n' bits from given position of a number
Sample execution        :   Enter num, n and val:10 3 5
                            Result = 50
*/


#include <stdio.h>

int toggle_nbits_from_pos(int, int, int);            //declaring a function of type integer to toggle'n' bits from given position of number

int main()
{
    int num, n, pos, res = 0;                        //declaring number, no of bits and result variables
      
    printf("Enter num, n and val:");                 //getting number, no of bits and position from the user and storing it
    scanf("%d%d%d", &num, &n, &pos);
    
    res = toggle_nbits_from_pos(num, n, pos);        //calling toggle_nbits_from_pos function with parameters num, n and val

    printf("Result = %d\n", res);                    //printing result returned from the function
}

int toggle_nbits_from_pos(int num, int n, int pos)    //function definition
{
    return ((((1 << n) - 1) << (pos - n + 1)) ^ num); //returning result
}

// Here ((1 << n) - 1) ---------> gives mask for given number for n bits

// (pos - n + 1) --------->  finds the no of times the mask has to be shifted to reach given position

//  (((1 << n) - 1) << (pos - n + 1)) ^ num -------> using ex-or with num will toggle n bits at given positions of the number
