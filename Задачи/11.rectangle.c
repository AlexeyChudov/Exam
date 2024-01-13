#include <stdio.h>

typedef struct Point
{
    int x;
    int y;
}point;
typedef struct Rect
{
    point left_bottom;
    point right_top;
}rect; 

int rect_perimeter(rect rectangle);

int main()
{   
    rect rect;
    printf("Введите координаты левого нижнего угла(x,y): ");
    scanf("%d %d", &rect.left_bottom.x, &rect.left_bottom.y);   
    printf("Введите координаты правого верхнего угла(x,y): ");
    scanf("%d %d", &rect.right_top.x, &rect.right_top.y);
    printf("Периметр прямоугольника равен: %d\n", rect_perimeter(rect));

    return 0;
}

int rect_perimeter(rect rectangle)
{
    return 2*((rectangle.right_top.y-rectangle.left_bottom.y) + (rectangle.right_top.x-rectangle.left_bottom.x));
}