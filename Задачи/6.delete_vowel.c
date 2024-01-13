#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define VOWEL_SIZE 6
#define MAXLEN 50

void delete_vowel(char * string);

int main()
{   
    char string[50];

    puts("Введите строку, состоящую из латинского алфавита: ");

    fgets(string, MAXLEN, stdin);

    delete_vowel(string);

    printf("Строка без гласных: %s\n", string);
}

void delete_vowel(char * string)
{
    int len = strlen(string)-1;
    char  vowel[] = "aoiuye";
    int del_index = -1;
    int last;
    int vowel_count = 0;

    for (int i = 0; i< len; i++)
        tolower(string[i]);

   while(strpbrk(string, vowel))
   {
        del_index = strpbrk(string, vowel)-string;
        vowel_count++;
        
            
        for (int d = del_index; string[d] != '\0' && del_index >= 0; d++)
        {
            string[d] = string[d+1];
            last = d;
            
        
        }
        del_index = -1;
    }
        
    
    string[len-vowel_count] = '\0';

    

}
