#include <stdio.h>
#include <string.h>
#define MAXLEN 50
 
int num_mult(char *string); 

int main()
{
    // char string[MAXLEN];

    // fgets(string, MAXLEN, stdin);

    // int num = num_mult(string);
    // printf("%d\n", num);

    int a[3][3] = {1, 2, 3, 4, 5};
    int (*p1)[3] = a;
    for (int i = 0; i<3;i++)
    {
        for (int j = 0;j<3;j++)
        {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
    

    return 0;
}

int num_mult( char *string)
{
    int mult = 1;
    if (strchr(string, '0'))
    {
        mult = 0;
        return mult;
    }

    for(int i = 0;string[i] != '\0'; i++)
    {
        
        if (string[i] <= '9' && string[i]>'0')
        {
            mult *= string[i]-'0';
        }
    }
    return mult;
}