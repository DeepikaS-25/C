/*
Name                    :   Deepika.S
Date                    :   07.07.2022
Description             :   Program to find which day of the year
Sample input            :   Enter the value of 'n' : 9
                            Choose First Day :
                            1. Sunday
                            2. Monday
                            3. Tuesday
                            4. Wednesday
                            5. Thursday
                            6. Friday
                            7. Saturday
                            Enter the option to set the first day : 3
Sample output           :   The day is Wednesday
*/

#include <stdio.h>
                                          
int main()
{
    int n;                                      //declaring nth day to a variable n
    printf("Enter the value of 'n' : ");        //gettting the value and storing it in n
    scanf("%d", &n);
        if (n <= 0 || n > 365)                  //checking whether the value of n is in between 1 and 365
        {
            printf("Error: Invalid Input, n value should be > 0 and <= 365");
        }
        else
        {
            int first;                               //declaring first day of the year as first
            printf("Choose First Day : ");            //providing options to set first day and getting the option
            printf("\n1. Sunday\n2. Monday \n3. Tuesday \n4. Wednesday \n5. Thursday \n6. Friday \n7. Saturday");
            printf("\nEnter the option to set the first day : ");
            scanf("%d", &first);
            if (first <= 0 || first > 7)           //if first value doesn't lie between range 0 to 7 then error is prompted
            {
                printf("Error: Invalid input, first day should be > 0 and <= 7");
            }
            else
            {
                int date, day;                       //declaring date and day variables
                date = n + first - 1;                //finding total no of days
                day = date % 7;                     //finding which day of week by getting modulus of total days
                switch (day)                         //using switch case to print the day of the week
                {
                    case 0:
                        printf("The day is Saturday");
                        break;
                    case 1:
                        printf("The day is Sunday");
                        break;
                    case 2:
                        printf("The day is Monday");
                        break;
                    case 3:
                        printf("The day is Tuesday");
                        break;
                    case 4:
                        printf("The day is Wednesday");
                        break;
                    case 5:
                        printf("The day is Thursday");
                        break;
                    case 6:
                        printf("The day is Friday");
                        break;
                }
            }
        }
    return 0;
}
