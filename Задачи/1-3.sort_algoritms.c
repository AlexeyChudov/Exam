#include <stdio.h>

int inversions(int * array, int len);
void selection_sort(int * arr, int len);
void bubble_sort(int * arr, int len);
void swap(int *a , int *b);
void print_array(int * arr, int len);
void insertion_sort(int *arr, int len);
void merge(int *arr,int *left_array, int *right_array, int left_len, int right_len);
void merge_sort(int *arr, int len);

int main()
{
    int len;
    printf("Введите длинну массива: ");
    scanf("%d", &len); 
    int array[len];

    printf("Введите элементы массива: ");
    for (int i = 0; i< len;i++)
    {scanf("%d", array+i);}

    // int left_array[len/2];
    // int right_array[len-len/2];

    // for (int i = 0; i < len/2; i++)
    // {
    //     left_array[i] = array[i];
    //     printf("left_array[%d] = %d\n", i, left_array[i]);
    // }
    // int k = 0;
    // for (int i = len-len/2; i < len; i++)
    // {
    //     right_array[k++] =  array[i];
    //     printf("i = %d, right_array[%d] = %d\n", i, k-1, right_array[k-1]);
        
    // }
    // int inv = inversions(array, len);
    // printf("%d\n", inv);
    //insertion_sort(array, len);
    // merge(array, left_array, right_array, len/2, len - len/2);
    bubble_sort(array, len);
    print_array(array, len);
    
    return 0;

}

int inversions(int * array, int len)
{
    int count = 0;
    for (int i = 0; i<len; i++)
    {
        for (int j = i+1; j<len; j++)
        {
            if (array[i] > array[j])
                count++;
        }
    }
    return count;
}

void bubble_sort(int *arr, int len)
{
    //Пузырьковая сортировка
    int max_index = len;
    while(max_index !=0)
    {
        int last_swapped = 0;
        for (int i = 1; i<max_index; i++){
            if (arr[i-1]> arr[i]){
                swap(arr+i-1, arr+i);
                last_swapped = i;            
            }
        }
        max_index = last_swapped;
    }
}
void selection_sort(int *arr, int len)
{
    //Сортировка выбором
    int min_index;
    for (int i = 0; i<len; i++)
    {
        min_index = i;
        for (int j = i+1; j< len; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
            swap(&arr[i], &arr[min_index]);
    }
}
void swap( int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void print_array(int * arr, int len)
{
    for (int i = 0; i< len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
} 

void insertion_sort(int *arr, int len)
{
    //Сортировка вставками
    int temp, k;
    for (int i = 1; i<len; i++)
    {
        temp = arr[i];
        k = i-1;
        while(k >=0 && arr[k]>temp)
        {
            swap(arr+k, arr+k+1);
            k--;
        }
    }
}

void merge(int *arr,int *left_array, int *right_array, int left_len, int right_len)
{
    //Функция слиянияя двух отсортированных массивов для сортировки слиянием
    int i = 0;// индекс основного массива 
    int left_p = 0;//индекс левого массива
    int right_p = 0;//индекс правого массива

    while(left_p < left_len && right_p < right_len)
    {
        if(left_array[left_p] < right_array[right_p])
        {
            arr[i] = left_array[left_p++]; 
        }
        else{
            arr[i] = right_array[right_p++];
        }
        i++;
    }
    
    while( left_p < left_len)
    {
        arr[i++] = left_array[left_p++];
    }
    
    while( right_p < right_len)
    {
        arr[i++] = right_array[right_p++];
    }
}

void merge_sort(int *arr, int len)
{
    //Сортировка слиянием
    if (len<2)
    {
        return;
    }
    int left_len = len/2+len % 2, right_len=len-left_len;
    int left_array[left_len];
    int right_array[right_len];
      
    int j;
    for (int i = 0; i < left_len; i++)
    {
        left_array[i] = arr[i];
        j = i;
    }

    int k = 0;
    for (j++; j < len; j++)
    {
        right_array[k++] =  arr[j];
    }
    merge_sort(left_array, left_len);
    merge_sort(right_array, right_len);
    merge(arr, left_array, right_array, left_len, right_len);

}