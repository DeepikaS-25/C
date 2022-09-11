/*
Name                    :   Deepika.S
Date                    :   25.08.2022
Description             :   Program to define a macro SIZEOF(x), without using sizeof operator
Sample execution        :   Size of int : 4 bytes
                            Size of char : 1 byte
                            Size of float : 4 bytes
                            Size of double : 8 bytes
                            Size of unsigned int : 4 bytes
                            Size of long int : 8 bytes
                            Size of long double : 16 bytes
                            Size of long long int : 8 bytes
                            Size of short : 2 bytes
                            Size of unsigned long int : 8 bytes
                            Size of unsigned long long int : 8 bytes
                            Size of unsigned short : 2 bytes
*/

#include <stdio.h>

#define SIZEOF(x)  ((char *)(&x + 1) - (char *)&x)                    //macro definition that gives result as sizeof() operator

int main()
{                                   //declaring variables of different data types
    int a;                          //a as integer
    char b;                         //b as character
	float c;                        //c as float
	double d;                       //d as double
	unsigned int e;                 //e as unsigned int
	long int f;                     //f as long int
	long double g;                  //g as long double
	long long int h;                //h as long long int
	short i;                        //i as short
	unsigned long int j;            //j as unsigned long int
	unsigned long long int k;       //k as unsigned long long int
	unsigned short l;               //l as unsigned short
                                                    //printing size of different datatypes by calling macro, in preprocessing the value of macro will be substituted in place of macro

	printf("Size of int : %zu bytes\n", SIZEOF(a));                       //calling macro with all the data types declared
	printf("Size of char : %zu byte\n", SIZEOF(b));
	printf("Size of float : %zu bytes\n", SIZEOF(c));
	printf("Size of double : %zu bytes\n", SIZEOF(d));
	printf("Size of unsigned int : %zu bytes\n", SIZEOF(e));
	printf("Size of long int : %zu bytes\n", SIZEOF(f));
	printf("Size of long double : %zu bytes\n", SIZEOF(g));
	printf("Size of long long int : %zu bytes\n", SIZEOF(h));
	printf("Size of short : %zu bytes\n", SIZEOF(i));
	printf("Size of unsigned long int : %zu bytes\n", SIZEOF(j));
	printf("Size of unsigned long long int : %zu bytes\n", SIZEOF(k));
    printf("Size of unsigned short : %zu bytes\n", SIZEOF(l));
	return 0;
}
