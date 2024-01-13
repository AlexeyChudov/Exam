
#include <stdio.h>
void spiral_arr(int **arr, int rows, int cols);

int main()
{
    int rows, cols;
    int shift = 0;
    int number = 1;//число, вносимое в матрицу
    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    int result[rows*cols];
  
    while(number <= cols*rows)
    {   
        for (int i = shift; i < cols - shift && (number <= cols*rows); i++)
        {
            matrix[shift][i] = number;
            //printf("i1 matrix[%d][%d]: %d, number: %d\n", shift, i, matrix[shift][i], number);
            number++;
        }
        for (int j = shift+1; j < rows - shift-1 && (number <= cols*rows);j++)
        {
            matrix[j][cols-shift-1] = number;
            //printf("j1 matrix[%d][%d]: %d, number: %d\n", j, cols-shift-1, matrix[j][cols-shift-1], number);

            number++;
        }
        
        for (int i = cols - shift - 1 ; i > shift-1 && (number <= cols*rows); i--)
        {
            matrix[rows - shift-1][i] = number;
            //printf("i2 matrix[%d][%d]: %d, number: %d\n", rows - shift-1, i, matrix[rows - shift-1][i], number);
            number++;
        }
        for (int j = rows-shift-2; (j > shift) && (number <= cols*rows);j--)
        {
            matrix[j][shift] = number;
            //printf("j2 matrix[%d][%d] : %d, number: %d\n", j, shift, matrix[j][shift], number);
            number++;
        }
        shift++;
    }
    

    for (int i = 0; i< rows ; i++)
    {
        for (int j  = 0; j < cols; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}



