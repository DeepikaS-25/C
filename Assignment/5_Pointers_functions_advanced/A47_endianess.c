/*
Name                    :   Deepika.S
Date                    :   11.08.2022
Description             :   Program to convert Little Endian data to Big Endian data
Sample execution        :   Enter the size: 2
                            Enter any number in Hexadecimal: AB
                            After conversion AB00
*/

#include <stdio.h>

int main()
{
    int size;                                           //declaring size
    unsigned num, result;                               //declaring num and result

    printf("Enter the size: ");                         //reading size of data from the user
    scanf("%d", &size);

    printf("Enter any number in Hexadecimal: ");       //getting hexadecimal number from the user
    scanf("%x", &num);

    char *ptr = &num;                                  //declaring a char pointer to point hexa num

    if (size == 4)                                     //checking size to convert endianess
    {
        unsigned int byte_1, byte_2, byte_3, byte_4;    //declaring unsigned byte1, 2, 3 and 4

        byte_1 = (0xFF & (*ptr++)) << 24;      //getting lsb using pointer and shifting it to msb and incrementing pointer to point next byte of data
        byte_2 = (0xFF & (*ptr++)) << 16;      //getting next lsb byte of data and shifting it in place after msb and incrementing pointer to point next byte of data
        byte_3 = (0xFF & (*ptr++)) << 8;       //getting next byte of data and shifting it to 3rd byte position and incrementing pointer to point next byte of data
        byte_4 =  0xFF & (*ptr);               //getting msb and keeping it in lsb

        result = (byte_1 | byte_2 | byte_3 | byte_4);
    }
    else
    {
        unsigned byte_1, byte_2;

        byte_1 = (0xFF & (*ptr++)) << 8;    //getting lsb using pointer and shifting it to msb
        byte_2 = 0xFF & (*ptr);             //getting msb and keeping it in lsb
        result = (byte_1) | (byte_2);
    }
    printf("After conversion %x", result);      //printing result after conversion
    return 0;
}
