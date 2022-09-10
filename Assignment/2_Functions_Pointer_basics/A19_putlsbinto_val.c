/*
Name                    :   Deepika.S
Date                    :   18.07.2022
Description             :   Program to put the (b-a+1) lsb’s of num into val[b:a]
Sample execution        :   Enter num, a, b, and val:11 3 5 174
                            Result = 158
*/

#include <stdio.h>

int replace_nbits_from_pos(int, int, int, int);             //declaring a function of type integer to

int main()
{
    int num, a, b, val, res = 0;                            //declaring number, a, b, val and result variables

    printf("Enter num, a, b, and val:");                    //getting number, a, b and value to replace from the user and storing it
    scanf("%d%d%d%d", &num, &a, &b, &val);

    res = replace_nbits_from_pos(num, a, b, val);           //calling replace_nbits_from_pos function with parameters num, a, b and val

    printf("Result = %d\n", res);                           //printing result returned from the function
}

int replace_nbits_from_pos(int num, int a, int b, int val)  //function definition
{
    return  ((((1 << (b - a + 1) ) - 1 ) & num) << a ) | (((~((1 << (b + 1)) - 1)) & val) | (((1 << a) - 1 ) & val));   //returns result
}


// (((1 << (b - a + 1) ) - 1 ) & num)  -----> getting (b - a + 1) bits from num
// ((((1 << (b - a + 1) ) - 1 ) & num) << a ) -----> left shifting it a times to replace in val
//((~((1 << (b + 1)) - 1)) & val) -----> clearing the bits from val to replace
//   ((((1 << (b - a + 1) ) - 1 ) & num) << a ) | (((~((1 << (b + 1)) - 1)) & val) | (((1 << a) - 1 ) & val)) gets bits from num and replaces it in val from position b
