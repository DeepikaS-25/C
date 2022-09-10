/*
Name                    :   Deepika.S
Date                    :   17.07.2022
Description             :   Program to get 'n' bits of a given position of a number
Sample execution        :   Enter num, n and val:15 2 2
                            Result = 3
*/

#include <stdio.h>

int get_nbits_from_pos(int, int, int);          //declaring a function of type integer to get 'n' bits of a given position of number

int main()
{
    int num, n, pos, res = 0;                   //declaring number, no of bits and result variables

    printf("Enter num, n and val:");            //getting number, no of bits and position from the user and storing it
    scanf("%d%d%d", &num, &n, &pos);

    res = get_nbits_from_pos(num, n, pos);      //calling get_nbits_from_pos function with parameters num, n and val

    printf("Result = %d\n", res);               //printing result returned from the function
}

int get_nbits_from_pos(int num, int n, int pos) //function definition
{
    return ((1 << n) - 1) & (num >> (pos - n + 1));    //returning result
}


// ((1 << n) - 1) & (num >> (pos - n + 1))
// Here ((1 << n) - 1) ---------> gives mask for given number for n bits

// (num >> (pos - n + 1)) --------->  finds the no of times the num has to be shifted to get for given position

//  ((1 << n) - 1) & (num >> (pos - n + 1)) -------> using and with above two results will get n bits at given position of the number


