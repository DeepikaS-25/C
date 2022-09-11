/*
Name                    :   Deepika.S
Date                    :   31.07.2022
Description             :   Program to count no. of characters, words and lines, entered through stdin
Sample execution        :   Hello world
                            Dennis Ritchie
                            Linux
                            Character count : 33
                            Line count : 3
                            Word count : 5
*/

#include<stdio.h>
int main()
{
    char ch, prev = '\0';                       /*declaring variables and initializing prev with nukk char*/
    int line_count = 0, word_count = 0, ch_count = 0;   /*initializing line, word and character count with 0*/
    for( ; (ch = getchar()) != EOF;)            /*getting char and running loop till ctrl+D*/
    {
        if(ch)
        {
            ch_count++;                         /*if char is entered char count is incremented*/
            if(ch == '\n')                      /*if new line(/n) is entered line count is incremented*/
            {
                line_count++;
            }
            if(((ch == ' ') || (ch == '\n') || (ch == '\t'))  && ((prev != ' ') && (prev != '\t') && (prev != '\n')))
            {                                   /*if new line(/n) or space or tab(/y) is entered then ensuring previous char was none of them */
                if(prev != '\0')                /*ensuring previous was not null*/
                {
                    word_count++;               /*then word count is incremented*/
                }
            }
        }
        prev = ch;                  /*assigning ch to previous*/
    }
    printf("Character count : %d\nLine count : %d\nWord count : %d", ch_count, line_count, word_count);     /*printing output*/
    return 0;
}
