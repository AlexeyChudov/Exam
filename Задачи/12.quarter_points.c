#include <stdio.h>
#define LEN 5

typedef struct point
{
    int x;
    int y;
} point;


void quarter_points(point p_arr[], int len, int quarter, point res_arr[]);

int main()
{
    point arr[LEN] = {{2,3}, {3, -2}, {0,1}, {-3, 2}, {-4, -1}};
    // for (int i = 0; i < LEN; i++)
    // {
    //     printf("Введите координаты точки(x, y), Не (0,0)!: ");
    //     scanf("%d %d", &arr[i].x, &arr[i].y);
    // }
    printf("Введите координатную четверть: ");
    int quarter;
    scanf("%d", &quarter);
    point res_arr[LEN];

    quarter_points(arr, LEN, quarter, res_arr);
    int i=0;
    printf("Координаты точек, лежащих в выбранной плоскости: ");
    while(res_arr[i].x != 0 && res_arr[i].y!=0)
    {
        printf("(%d, %d) ", res_arr[i].x,res_arr[i].y);
        i++;
    }
    putchar('\n');

    return 0;
}

void quarter_points(point p_arr[], int len, int quarter, point res_arr[])
{
    int count;
    point temp_arr[len];
    switch (quarter)
    {
    case 1:
        for(int i = 0, r_i = 0; i< len; i++)
        {
            if (p_arr[i].x>0 && p_arr[i].y>0){
                temp_arr[r_i++] = p_arr[i];
                count++;
            }
        }
        break;

    case 2:
        for(int i = 0, r_i = 0; i< len; i++)
        {
            if (p_arr[i].x<0 && p_arr[i].y>0){
                temp_arr[r_i++] = p_arr[i];
                count++;
            }
        }    
        break;
    case 3:
        for(int i = 0, r_i = 0; i< len; i++)
        {
            if (p_arr[i].x<0 && p_arr[i].y<0){
                temp_arr[r_i++] = p_arr[i];
                count++;
            }
        }    
        break;
    case 4:
        for(int i = 0, r_i = 0; i< len; i++)
        {
            if (p_arr[i].x>0 && p_arr[i].y<0){
                temp_arr[r_i++] = p_arr[i];
                count++;
            }
        }   
        break;
    }
    for (int i = 0; i<count;i++)
    {
        res_arr[i] = temp_arr[i];
    }
    for(int i = count ; i< len;i++)
    {
        res_arr[i].x = 0;
        res_arr[i].y = 0;
    }
     
}
