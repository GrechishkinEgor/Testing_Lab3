#include <iostream>
#include <Windows.h>
#include "Matrix.h"

void InputMatrix(Matrix& mat)
{
    int rowsCount = 0, colsCount = 0;
    do
    {
        system("cls");
        printf("Введите размеры матрицы: ");
        scanf_s("%d%d", &rowsCount, &colsCount);
        while (getchar() != '\n');
    } while (rowsCount <= 0 || colsCount <= 0);

    mat.Resize(rowsCount, colsCount);

    printf("Введите данные матрицы:\n");
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < colsCount; j++)
            scanf_s("%lf", &mat[i][j]);
}

void PrintMatrix(Matrix& mat)
{
    for (int i = 0; i < mat.GetRowsCount(); i++)
    {
        for (int j = 0; j < mat.GetColsCount(); j++)
            printf("%lf ", mat[i][j]);
        printf("\n");
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Matrix currMat;
    InputMatrix(currMat);  
    
    char userChoice = 0;
    do
    {
        system("cls");
        printf("Текущая матрица: \n");
        PrintMatrix(currMat);

        printf("Выберите действие:\n");
        printf("1. Ввести матрицу заново\n");
        printf("2: Транспонировать матрицу\n");
        printf("3: Умножить матрицу на число\n");
        printf("4: Посчитать определитель\n");

        printf("5: Сложить матрицы\n");
        printf("6: Умножить матрицу на матрицу\n");

        printf("0: Выйти из программы\n");
        printf("Ваш выбор: ");
        scanf_s("%hhd", &userChoice);
        while (getchar() != '\n');

        switch (userChoice)
        {
        case 1:
            InputMatrix(currMat);
            break;
        case 2:
            currMat = Matrix::Transpose(currMat);
            break;
        case 3:
        {
            double multiplier = 0;
            printf("Введите множитель: ");
            scanf_s("%lf", &multiplier);
            while (getchar() != '\n');
            currMat = Matrix::MultByNum(currMat, multiplier);
            break;
        } 
        case 4:
            printf("Определитель: %lf\n", currMat.Det());
            system("pause");
            break;
        case 5:
        {
            Matrix newMat(currMat.GetRowsCount(), currMat.GetColsCount());
            printf("Введите данные второй матрицы:\n");
            for (int i = 0; i < currMat.GetRowsCount(); i++)
                for (int j = 0; j < currMat.GetColsCount(); j++)
                    scanf_s("%lf", &newMat[i][j]);
            currMat = Matrix::Sum(currMat, newMat);
            break;
        }
        case 6:
        {
            int colsCount = 0;
            do
            {
                printf("Введите кол-во столбцов во второй матрице: ");
                scanf_s("%d", &colsCount);
                while (getchar() != '\n');
            } while (colsCount <= 0);
            Matrix newMat(currMat.GetColsCount(), colsCount);
            printf("Введите данные второй матрицы:\n");
            for (int i = 0; i < currMat.GetColsCount(); i++)
                for (int j = 0; j < colsCount; j++)
                    scanf_s("%lf", &newMat[i][j]);
            currMat = Matrix::Multiply(currMat, newMat);
            break;
        }
        default:
            break;
        }
    } while (userChoice != 0); 
}
