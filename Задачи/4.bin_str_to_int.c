#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXLEN 8

int bin_str_to_int(char string[], int len);

int main()
{
    char str_num[MAXLEN] = "00000000";
    int len;
    int result;

    puts("Введите двоичное число или 'q' для входа");
    scanf("%s", str_num);
    while(str_num[0] != 'q')
    {
        len = strlen(str_num);

        result = bin_str_to_int(str_num, len);
        printf("Result: %d\n", result);
        puts("Введите двоичное число или 'q' для входа");
        scanf("%s", str_num);
    }
    return 0;
}

int bin_str_to_int(char string[], int len)
{
    int result = 0;
    int digit = len-1;

    for (int i = 0; i< len; i++, digit--)
    {
        result+= (string[i]-'0') * pow(2, digit);
    }
    return result;

}