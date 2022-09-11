/*
Name                    :   Deepika.S
Date                    :   01.09.2022
Description             :   Program to implement the student record using array of structures
Sample execution        :   Enter no.of students : 2
                            Enter no.of subjects : 2
                            Enter the name of subject 1 : Maths
                            Enter the name of subject 2 : Science
                            ----------Enter the student details-------------
                            Enter the student Roll no. : 1
                            Enter the student 1 name : Nandhu
                            Enter Maths mark : 99
                            Enter Science mark : 91
                            ----------Enter the student details-------------
                            Enter the student Roll no. : 2
                            Enter the student 2 name : Bindhu
                            Enter Maths mark : 88
                            Enter Science mark : 78
                            ----Display Menu----
                            1. All student details
                            2. Particular student details
                            Enter your choice : 2

                            ----Menu for Particular student----
                            1. Name.
                            2. Roll no.
                            Enter you choice : 1
                            Enter the name of the student : Nandhu
                            Roll No.     Name           Maths         Science       Average       Grade
                            1            Nandhu          99             91           95              A
                            Do you want to continue to display(Y/n) : n
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int my_strcmp(const char *, const char *);          //declaration of string compare function

struct Subjects
{
    char sub_name[20];                             //declaring structure for subject names
};
struct Student                                      //declaring structure for student records holding id, name, marks, average, grade
{
    int id;
    char name[20];
    int marks[100];
    float average;
    char grade;
};

int main()
{
    int std_no, i, j, sub_no, sum, count, choice, option, search_id, match;         //declaring necessary vaariables
    char opt, string[20];
    printf("Enter no of students:");                       //getting no of students from the user
    scanf("%d", &std_no);

    struct Student record[std_no];                          //creating a structure of array of size student no

    printf("Enter no of subjects:");                        //getting no of subjects from the user
    scanf("%d", &sub_no);

    struct Subjects s_name[sub_no];                         //creating a structure of array of size subject no
    for(i = 0; i < sub_no; i++)
    {
        printf("Enter the  name of subject %d : ", i+1);       //getting subject names from the user
        __fpurge(stdin);
        scanf("%[^\n]", s_name[i].sub_name);                    //storing subject name in array of structure
    }
    for(i = 0; i < std_no; i++)                             //getting student details from the user and storing it in the structure
    {
        printf("----------Enter the student datails-------------\n");
        printf("Enter the student Roll no. : ");
        scanf("%d", &record[i].id);
        printf("Enter the student %d name : ", i+1);
        __fpurge(stdin);
        scanf("%[^\n]", record[i].name);
        count = 0;
        sum = 0;
        for(j = 0; j < sub_no; j++)
        {
          printf("Enter %s mark : ", s_name[j].sub_name);          //getting subject marks and storing it in array of marks in structure
          scanf("%d", &record[i].marks[count]);                  //using a count variable as index to access the array elements
          sum = sum + record[i].marks[count];                   //finding sum to compute average
          count++;                                              //incrementing count to access the next element at next iteration
        }
        record[i].average = (float) sum / sub_no;               //finding average
        if (record[i].average >= 90)                            //computing grade based on conditions
        {
             record[i].grade = 'A';
        }
        else if ((record[i].average >= 80) && (record[i].average < 90))
        {
            record[i].grade = 'B';
        }
        else if ((record[i].average >= 70) && (record[i].average < 80))
        {
            record[i].grade = 'C';
        }
        else if ((record[i].average >= 60) && (record[i].average < 70))
        {
            record[i].grade = 'D';
        }
        else if ((record[i].average >= 50) && (record[i].average < 60))
        {
            record[i].grade = 'E';
        }
        else
        {
            record[i].grade = 'F';
        }
    }

    do
    {
        printf("\n----Display Menu----\n1. All student details\n2. Particular student details\n\nEnter your choice : ");
        scanf("%d", &choice);                                       //displaying menu and getting choice
        switch (choice)                                             //using switch case for choice
        {
            case 1:                                             //displaying all student details if case 1 is selected
                   printf("%-13s%-15s","Roll No.","Name");      //displaying title
                   for(j = 0; j < sub_no; j++)
                   {
                        printf("%-14s", s_name[j].sub_name);
                        fflush(stdout);
                   }
                   printf("%-14s%s\n", "Average", "Grade" );
                   for(i = 0; i < std_no; i++)                //displaying details for all students
                   {
                        fflush(stdout);
                        printf("%-13d%-15s", record[i].id, record[i].name);
                        for(j = 0; j < sub_no; j++)
                        {
                            fflush(stdout);
                            printf("%-14d", record[i].marks[j]);
                        }
                        printf("%-15g", record[i].average);
                        printf("%c\n", record[i].grade);
                    }
                    break;
            case 2:                                     //case 2 for particular student details
                printf("\n\n----Menu for Particular student----\n1. Name.\n2. Roll no.\n\nEnter you choice : ");
                scanf("%d", &option);                           //getting option for finding student either with name or roll.no
                switch (option)
                {
                    case 1:                         //case 1 for name
                        printf("\nEnter the name of the student : ");
                        scanf("%s", string);
                        for (match = 0; match < std_no; match++)            //getting name and finding matching name of student in record
                        {
                            if ((my_strcmp(record[match].name, string)) == 0)       //using strcmp() to compare names
                            {
                                printf("\n%-13s%-15s","Roll No.","Name");
                               for(j = 0; j < sub_no; j++)
                               {
                                    printf("%-14s", s_name[j].sub_name);
                                    fflush(stdout);
                               }
                               printf("%-14s%s\n", "Average", "Grade" );
                               printf("%-13d%-15s", record[match].id, record[match].name);          //once match is found then printing details of that particular student
                               for(j = 0; j < sub_no; j++)
                               {
                                    fflush(stdout);
                                    printf("%-14d", record[match].marks[j]);
                               }
                               printf("%-15g", record[match].average);
                               printf("%c\n", record[match].grade);
                            }
                        }
                        break;
                    case 2:                                 //case 2 for roll.no
                        printf("\nEnter the Roll no. of the student : ");
                        scanf("%d", &search_id);                //getting search_id
                        for (match = 0; match < std_no; match++)
                        {
                            if (record[match].id == search_id)      //searching for matching roll.no
                            {
                                printf("%-13s%-15s","Roll No.","Name");
                                for(j = 0; j < sub_no; j++)
                                {
                                    printf("%-14s", s_name[j].sub_name);
                                    fflush(stdout);
                                }
                                printf("%-14s%s\n", "Average", "Grade" );
                                printf("%-13d%-15s", record[match].id, record[match].name);     //once match is found then printing details of that particular student
                                for(j = 0; j < sub_no; j++)
                                {
                                    fflush(stdout);
                                    printf("%-14d", record[match].marks[j]);
                                }
                                printf("%-15g", record[match].average);
                                printf("%c\n", record[match].grade);
                            }
                        }
                        break;
                     default :
                        printf("\nError : Invalid Option");                 //prompting error in default case
                }
                break;
            default :
                printf("\nError : Invalid Option");                         //prompting error in default case
         }
            __fpurge(stdin);
            printf("\n\nDo you want to continue to display(Y/n) : ");       //displaying option for continue or quit
            scanf("%c", &opt);

      } while (opt == 'y' || opt == 'Y');                       //do while loop to run only for y or Y
    return 0;

}

int my_strcmp(const char *str1, const char *str2)       //string compare function definition
{
    while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2)     //comparing till null and same character
    {
        str1++;
        str2++;
    }
    return (*str1 - *str2);                            //returning difference when characters are unequal
}
