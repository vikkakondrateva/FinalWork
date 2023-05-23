#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void inputArray(int* array, int row, int col);
void outputArray(int* array, int row, int col);
int processArray(int* array, int row, int col);
void outputResult(int result);


int main()
{
    setlocale(LC_ALL, "Russian");

    int m[5][5];
    int res;

    inputArray((int*)m, 5, 5);//m-указатель на int
    outputArray((int*)m, 5, 5);
    res = processArray((int*)m, 5, 5);
    outputResult(res);
    
    return 0;
}

void inputArray(int* array, int row, int col) // row-строка, col-столбец
{
    srand(time(NULL));
    for (int il = 0; il < row; il++)
    {
        for (int il = 0; il < col; il++)
        {
            do
            {
                *array = rand() - RAND_MAX / 2;
            }
            while (*array == 0);
            array++;
        }
    }
}

void outputArray(int* array, int row, int col)
{
    for (int il = 0; il < row; il++)
    {
        for (int il = 0; il < col; il++)
        {
            printf("%8d ", *array);
            array++;
        }
        printf("\n");
    }
}

int processArray(int* array, int row, int col)
{
    int c = 0;
    int minus = 0;
    if (*array < 0)
        minus = 1;


    for (int il = 0; il < row; il++)
    {
        for (int il = 0; il < col; il++)
        {
            if ((minus == 0) && (*array < 0))
            {
                c++;
                minus = 1;
            }
            else if ((minus == 1) && (*array > 0))
            {
                c++;
                minus = 0;
            }
            array++;
        }
    }
    return c;
}

void outputResult(int result)
{
    printf("Элементы массива меняют знак %d раз\n", result);
}