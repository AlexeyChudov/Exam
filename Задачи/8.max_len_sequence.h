
#include <string.h>
#define ALPLEN 26

int max_len_sequence(char string[])
{
    int n;
    int index = 0;
    int temp_count = 1;//Переменный счетчик последовательности
 
    int max_count = 0;//Длина наибольшей последовательности
    

    for (int i =0; string[i]!='\0';i++)
    {
        if (string[i+1]==string[i]+1){
            temp_count++;
        }
        else{
            if (temp_count>max_count)
            {
                max_count = temp_count;
            }
            temp_count = 1;
        }
    }
    return max_count;
}


 // for (int i = 0; i < len-1; i++)
    // {
    //     for (int j = 0; j< ALPLEN-1; j++)
    //     {
    //         index = string[i] == alp[j] ? j : 0;
    //     }
    //     if (string[i+1] == alp[index+1])
    //     {
    //         temp_count++;
    //     }
    //     else{
    //         if (temp_count>max_count){
    //             max_count = temp_count;
    //         }
    //         temp_count = 1;   
    //     }
    // }
    // if (temp_count > max_count)
    //     {
    //         max_count = temp_count;   
    //     } 