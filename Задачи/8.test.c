#include <stdio.h>
#include "8.max_len_sequence.h"
#define MAXLEN 50

int main()
{   
    char string[MAXLEN];

    printf("Введите строку из Латинских букв: ");
    fgets(string, MAXLEN, stdin);

    int res = max_len_sequence(string);

    printf("%d\n", res);
    printf("%zu\n", sizeof(long int));


}

