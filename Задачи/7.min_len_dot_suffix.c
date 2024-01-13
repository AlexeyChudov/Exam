#include <stdio.h>

char * min_len_dot_suffix(char*);

int main()
{
    char string[10];
    puts("Введите строку для поиска суффикса: ");
    scanf("%s", string);
    char * suffix = min_len_dot_suffix(string);
    fputs(suffix, stdout);
    putchar('\n');
    return 0;

}


char * min_len_dot_suffix(char* str)
{
    int len=1;
    while(str[len]!='\0')
    //Находим длину строки
    {
        len++;
    }
    char * suffix_start;
    for(suffix_start = str+len-1; *suffix_start!='.'&&suffix_start>str;suffix_start--);
    if (suffix_start == str && *str != '.')
    {
        return "There's no dots in the string";
    }

    return suffix_start;
}