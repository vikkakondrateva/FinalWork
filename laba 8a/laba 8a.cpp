#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void inputArray(int* array, int size);// обявляем прототип функции(прототип-информация для компилятора)
void outputArray(int* array, int size);
double processArray(int* array, int size);
void outputResult(double result);

//#define SIZE 10 //константа

int main()
{
    setlocale(LC_ALL, "Russian");

    int m[10];
    double res;
  
    inputArray(m, 10); //вызываются
    outputArray(m, 10);
    res = processArray(m, 10);
    outputResult(res);

    return 0;
}

void inputArray(int* array, int size)//заголовок функции: тип возвращ знач, имя функции, параметры
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        *array = rand();
        array++;
    }
}

void outputArray(int* array, int size) // void-функция не возвращ знач(пустой тип)
{
    printf("Массив случайных чисел: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", *array);
        array++;
    }
}

double processArray(int* array, int size)
{
    double g = 1;
    for (int i = 0; i < size; i++)
    {
        g = g * (*array);
        array++;
    }
    g = pow(g, 0.1);
    return g;//возвращаемое значение
}

void outputResult(double result)
{
    printf("Среднее геометрическое массива: \n");
    printf("%lf\n", result);
}