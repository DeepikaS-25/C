/*
Name                    :   Deepika.S
Date                    :   25.08.2022
Description             :   Program to define a macro SIZEOF(x), without using sizeof operator
Sample execution        :   1. Int
                            2. char
                            3. short
                            4. float
                            5. double
                            6. string
                            Enter you choice : 1

                            Enter the num1 : 105
                            Enter the num2 : 205
                            After Swapping :
                            num1 : 205
                            num2 : 105
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
                //defining a macro with arguments t(data type of x and y) and two variables x and y to be swapped
                //declaring a temp variable to swap with data type as t. Swapping the variables passed to macro
#define SWAP(t, x, y)       \
{                           \
     t temp;                \
     temp = x;              \
     x = y;                 \
     y = temp;              \
}                           \

int main()
{
    int choice;                     //declaring choice
                                    //providing choices of data type to swap
    printf("1. Int\n2. char\n3. short\n4. float\n5. double\n6. string\n");
    int num1, num2;                 //declaring variables of different data types to read and swap
    char char1, char2;
    short short1, short2;
    float float1, float2;
    double double1, double2;
    char *str1;                     //declaring two char pointers str1 and str2 to read two strings and swap them
    char *str2;
    printf("Enter your choice : ");         //reading choice from the user
    scanf("%d", &choice);
    printf("\n");
    switch (choice)
    {
        case 1:
                                                    //if choice is int
            printf("Enter the num1 : ");
            scanf("%d", &num1);                     //reading num1 and num2 from the user
            printf("Enter the num2: ");
            scanf("%d", &num2);
            SWAP(int, num1, num2);                  //calling macro with data type int and 2 numbers to swap
            printf("After Swapping : \n");          //printing result after swapping
            printf("num1 : %d\nnum2 : %d", num1, num2);
            break;
        case 2:
                                                    //if choice is char
            printf("Enter the char1 : ");           //reading 2 charaters from the user
            __fpurge(stdin);                          //flushing input stream to read a char
            scanf("%c", &char1);
            printf("Enter the char2: ");
            __fpurge(stdin);                         //flushing input stream to read a char
            scanf("%c", &char2);
            SWAP(char, char1, char2);              //calling macro with data type char and 2 chars to swap
            printf("After Swapping : \n");         //printing result after swapping
            printf("char1 : %c\nchar2 : %c", char1, char2);
            break;
        case 3:
                                                    //if choice is short
            printf("Enter the short1 : ");
            scanf("%hd", &short1);                  //reading 2 short numbers from the user
            printf("Enter the short2 : ");
            scanf("%hd", &short2);
            SWAP(short, short1, short2);            //calling macro with data type short and 2 numbers to swap
            printf("After Swapping : \n");          //printing result after swapping
            printf("short1 : %hd\nshort2 : %hd", short1, short2);
            break;
        case 4:
                                                    //if choice is float
            printf("Enter the float1 : ");
            scanf("%f", &float1);                  //reading 2 float numbers from the user
            printf("Enter the float2: ");
            scanf("%f", &float2);
            SWAP(float, float1, float2);            //calling macro with data type float and 2 numbers to swap
            printf("After Swapping : \n");          //printing result after swapping
            printf("float1 : %f\nfloat2 : %f", float1, float2);
            break;
        case 5:
                                                    //if choice is double
            printf("Enter the double1 : ");
            scanf("%lf", &double1);                 //reading 2 float numbers from the user
            printf("Enter the double2: ");
            scanf("%lf", &double2);
            SWAP(double, double1, double2);        //calling macro with data type double and 2 numbers to swap
            printf("After Swapping : \n");         //printing result after swapping
            printf("double1 : %lf\ndouble2 : %lf",double1, double2);
            break;
        case 6:
                                                        //if choice is string
            str1 = (char *)malloc(sizeof(char)*40);     //dynamically allocating memory for the str1
            str2 = (char *)malloc(sizeof(char)*40);     //dynamically allocating memory for the str2
            printf("Enter the str1 : ");                //reading 2 strings from the user
            __fpurge(stdin);                              //flushing input stream to read a string
            scanf("%[^\n]", str1);
            printf("Enter the str2: ");
            __fpurge(stdin);                              //flushing input stream to read a string
            scanf("%[^\n]", str2);
            SWAP(char*, str1, str2);                    //calling macro with data type char pointer and 2 strings to swap
            printf("After Swapping : \n");              //printing result after swapping
            printf("str1 : %s\nstr2 : %s", str1, str2);
            break;
        default:
            printf("Invalid choice");                   //prompting error for invalid choice
    }
    return 0;
}
