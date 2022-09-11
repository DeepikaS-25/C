/*
Name                    :   Deepika.S
Date                    :   19.08.2022
Description             :   Program to provide a menu to add or display or remove a variable
Sample execution        :   Menu :
                            1. Add element
                            2. Remove element
                            3. Display element
                            4. Exit from the program
                            Choice ---> 1
                            Enter the type you have to insert:
                            1. int
                            2. char
                            3. float
                            4. double
                            Choice ---> 2
                            Enter the char : k
                            1. Add element
                            2. Remove element
                            3. Display element
                            4. Exit from the program
                            Choice ---> 3
                            -------------------------
                            0 -> k
                            -------------------------
                            1. Add element
                            2. Remove element
                            3. Display element
                            4. Exit from the program
                            Choice ---> 1
                            Enter the type you have to insert:
                            1. int
                            2. char
                            3. float
                            4. double
                            Choice ---> 1
                            Enter the int : 10
                            1. Add element
                            2. Remove element
                            3. Display element
                            4. Exit from the program
                            Choice ---> 3
                            ------------------------
                            0 -> k (char)
                            1 -> 10 (int)
                            ------------------------
                            1. Add element
                            2. Remove element
                            3. Display element
                            4. Exit from the program
                            Choice ---> 2
                            0 -> k
                            1 -> 10
                            Enter the index value to be deleted : 0
                            index 0 successfully deleted.
                            1. Add element
                            2. Remove element
                            3. Display element
                            4. Exit from the program
                            Choice ---> 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void print_menu(char **menu, int size);             //function declaration for printing menu

int main()
{
    int ch, option, index;                          //declaring variables
    void *ptr = malloc(8);                          //dynamic memory allocation for void pointer to hold any datatype
                //creating flags for every datatype and initializing with 0 and updating them with 1 when data is read
    int char_flag1 = 0, char_flag2 = 0, short_flag = 0, int_flag = 0, float_flag = 0, double_flag = 0;
    char *s[4] = {"Add element","Remove element","Display element","Exit from the program"};    //string for first menu
    char *str[5] = {"int","char","float","double","short"};         //string for second menu
    printf("Menu :\n");
   
    while(ch != 4)                  //while loop to exit when choice 4 is selected
    {
        print_menu(s, 4);           //function call to print menu
        printf("Choice ---> ");
        scanf("%d", &ch);           //reading choice
        switch (ch)
        {
            case 1:                     //when add element is chosen menu will be printed to select the dataype we want to enter
                printf("Enter the type you have to insert:\n");
                print_menu(str, 5);     //function call to print menu of datatype
                printf("Choice ---> ");
                scanf("%d", &option);   //reading choice
                
                switch (option)
                {                   //when a datatype is chosen then we are checking whether space is available or not if not available then printing insufficient space
                    case 1:         //in a pointer either 2 char and 1 short and 1 integer or 1 float can only be stored else a double only can be stored
                        if (int_flag == 0 && float_flag == 0 && double_flag == 0)   //checking whether int, float, double are 0, then getting int
                        {
                            printf("Enter the int : ");
                            scanf("%d", (int *)(ptr + 4));
                            int_flag = 1;       //after reading any datatype updating flag with 1 to prevent adding again
                        }
                        else
                            printf("Insufficient space\n");
                        break;
                        
                    case 2:
                        if (char_flag1 == 0 && double_flag == 0) //checking whether char1 and double are 0, then getting char
                        {
                            __fpurge(stdin);
                            printf("Enter the char : ");
                            scanf("%c", (char *)ptr);
                            char_flag1 = 1;
                        }
                        else if (char_flag2 == 0 && double_flag == 0)   //checking whether char2 and double are 0, then getting char
                        {
                            __fpurge(stdin);
                            printf("Enter the char : ");
                            scanf("%c", (char *)(ptr + 1));
                            char_flag2 = 1;
                        }
                        else
                            printf("Insufficient space\n");
                        break;
                        
                    case 3:
                        if (float_flag == 0 && int_flag == 0 && double_flag == 0)  //checking whether int, float, double are 0, then getting float
                        {
                            printf("Enter the float : ");
                            scanf("%f", (float *)(ptr + 4));
                            float_flag = 1;
                        }
                        else
                            printf("Insufficient space\n");
                        break;
                        
                    case 4:                   //checking whether all flags are zero, then getting double
                        if (char_flag1 == 0 && char_flag2 == 0 && short_flag == 0 && int_flag == 0 && float_flag == 0 && double_flag ==0)
                        {
                            printf("Enter the double : ");
                            scanf("%lf", (double *)ptr);
                            double_flag = 1;
                        }
                        else
                            printf("Insufficient space\n");
                        break;
                        
                    case 5:
                        if (double_flag == 0 && short_flag == 0)      //checking whether double and short are 0, then getting short
                        {
                            printf("Enter the short : ");
                            scanf("%hd", (short *)(ptr + 2));
                            short_flag = 1;
                        }
                        else
                            printf("Insufficient space\n");
                        break;
                        
                    default:
                        printf("Invalid choice\n");                 //if choice is not one of given then prompting error
                        break;
                }
                break;
                
          case 2:                       //when removing element is chosen displaying all the available variable
				if (int_flag == 1)
                {                         //displaying integer with index
                    printf("4 -> %d\n", *(int *)(ptr + 4));
                }
				if (char_flag1 == 1)
                {                         //displaying char1 with index
                    printf("0 -> %c\n", *(char *)ptr);
                }
				if (char_flag2 == 1)
                {                         //displaying char2 with index
                    printf("1 -> %c\n", *(char *)(ptr + 1));
                }
				if (float_flag == 1)
                {                       //displaying float with index
                    printf("4 -> %f\n", *(float *)(ptr + 4));
                }
				if (double_flag == 1)
                {                        //displaying double with index
                    printf("0 -> %lf\n", *(double *)ptr);
                }
                if (short_flag == 1)
                {                        //displaying short with index
                    printf("2 -> %hd\n", *(short *)(ptr + 2));
                }
                
				printf("Enter the index value to be deleted : ");
				scanf("%d", &index);       //reading index
				printf("index %d successfully deleted\n", index);
				
				if (index == 4 && int_flag == 1)
                {
					int_flag = 0;              //setting flag to 0 after getting index
                }
				else if (index == 0 && char_flag1 == 1)
                {
                    char_flag1 = 0;
                }
				else if (index == 1 && char_flag2 == 1)
                {
					char_flag2 = 0;
                }
                else if (index == 4 && float_flag == 1)
				{
				    float_flag = 0;
				}
                else if ( index == 0 && double_flag == 1)
                {
                    double_flag = 0;
                }
				else if (index == 2 && short_flag == 1)
                {
					short_flag = 0;
                }
                else
                {
                    printf("Invalid index");
                }
              break;
              
            case 3:             //when displaying element is chosen displaying all the available variable
                    printf("------------------------\n");
                    if (char_flag1 == 1)
                    {
                        printf("0 -> %c\n", *(char *)ptr);
                    }
                    if (char_flag2 == 1)
                    {
                        printf("1 -> %c\n", *(char *)(ptr + 1));
                    }
                    if (double_flag == 1)
                    {
                        printf("0 -> %lf\n", *(double *)ptr);
                    }
                    if (short_flag == 1)
                    {
                        printf("2 -> %hd\n", *(short *)(ptr + 2));
                    }
                    if (int_flag == 1)
                    {
                        printf("4 -> %d\n", *(int *)(ptr + 4));
                    }
                    if (float_flag == 1)
                    {
                            printf("4 -> %f\n", *(float *)(ptr + 4));
                    }
                    printf("------------------------\n");
                    break;
        }
    }
    free(ptr);              //freeing pointer
    return 0;
}

void print_menu(char **menu, int size)              //function definition to print menu of size given through funciton call
{
   for(int i = 0; i < size; i++)                   //loop to print menu items till the size
    {
        printf("%d. %s\n", i+1, menu[i]);           //printing menu
    }
}
