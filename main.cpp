#include <iostream>

int main()
{   
    unsigned short N, M = 0;
    int A[100][100] = {0};
    int B[100];


    std::cin >> N >> M;

    for(unsigned short i = 0; i < N; i++)   // Задает всем эл-ам массива 'B' значения 1
    {
        B[i] = 1;
    }

    if((N > 100) || (N <= 0) || (M > 100) || (M <= 0))  // Ошибка при неверном вводе параметров матрицы
    { 
        std::cout << "Error!!!";
        return 0;
    }   
    

    for(unsigned short i = 0; i < N; i++)   // Считывает массив с консоли
    {
        for(unsigned short j = 0; j < M; j++)
        {
            std::cin >> A[i][j];
        }
    }

    for(unsigned short i = 0; i < N; i++)   // записать в i-тый элемент массива 'B' произведение элементов i-ого столбца массива 'A'
    {
        for(unsigned short j = 0; j < M; j++)
        {
            B[i] = B[i]*A[i][j];
        }
    }

    long long maximalProduct = INT_MIN;
    unsigned short numberOfMaxProduct = 0;

    for(unsigned short i = 0; i < N; i++)   //находит максимальное произведение в массиве и задает переменной 'numberOfMaxProduct' значение, соответствующее номеру столбца матрицы с максимальным произведением
    {
        if(B[i] > maximalProduct)
        {
            maximalProduct = B[i];
            numberOfMaxProduct = i;
        }
    }


    for(unsigned short i = 0; i<N; i++) //Выводит матрицу до изменений в элементах
    {
        for(unsigned short j = 0; j<M; j++)
        {
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "/////////////////" << std::endl;
    

    for(unsigned short j = 0; j < M; j++)   //Производит изменения над элементами столбца с максимальным произведением
    {
        A[j][numberOfMaxProduct] = A[j][numberOfMaxProduct] - 3;
    }

    for(unsigned short i = 0; i<N; i++)     // Выводит матрицу после изменений
    {
        for(unsigned short j = 0; j<M; j++)
        {
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "----------------------------" << std::endl;

    for(unsigned short i = 0; i < N; i++)
    {
        std::cout << B[i] << "\t";
    }
    




    return 0;
}