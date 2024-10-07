#include <iostream>

int sumOfDigits(int x);
short minimalDigitInNumber(int x);

int main()
{
    int A[3][1000] = {0};
    unsigned short N = 0;

    std::cin >> N;

    for(unsigned short i = 0; i < N; i++)   //Считывает массив с консоли
    {
        std::cin >> A[0][i];
    }

    int replacement = 0;

    /*for(unsigned short i = 0; i < N - 1; i++)   // Сортирует swap-ом элементы массива
    {
        for(unsigned short j = i+1; j < N; j++)
        {
            if(A[0][i] > A[0][j])
            {
                replacement = A[0][i];
                A[0][i] = A[0][j];
                A[0][j] = replacement;
            }
            
        }
    }*/

    

    for(unsigned short i = 0; i < N; i++)   // Карждому элементу подбиает сумму цифр элемента и минимальную цифру в числе
    {
        A[1][i] = sumOfDigits(A[0][i]);
        A[2][i] = minimalDigitInNumber(A[0][i]);
    }


    int rep1 = 0;
    int rep2 = 0;
    int rep3 = 0;


    for(unsigned short i = 0; i < N-1; i++)     // Сортировка массива swap-ом по сумме цифр в числе
    {
        for(unsigned j = i+1; j < N; j++)
        {
            if(A[1][i] > A[1][j])
            {
                rep1 = A[0][i];
                rep2 = A[1][i];
                rep2 = A[2][i];

                A[0][i] = A[0][j];
                A[1][i] = A[1][j];
                A[2][i] = A[2][j];

                A[0][j] = rep1;
                A[1][j] = rep2;
                A[2][j] = rep3;
            }
        }
    }








    return 0;
}





int sumOfDigits(int x)  // Ф-я, возвращающая сумму цифр в числе
{
    int sum = 0;
    x = abs(x);
    while(x!=0)
    {
        sum = sum + x%10;
        x = x / 10;
    }
    
    return sum;
}



short minimalDigitInNumber(int x)       // Ф-я, возвращающая наименьшую цифру числа
{
    x = abs(x);
    int B[100] = {0};
    unsigned short l = 0;

    for(unsigned short k = 0; x!=0; k++)    // "Дробит" число на цифры и закладывает каждую цифру в массив
    {
        B[k] = x%10;
        x = x/10;
        l = l+1;
    }

    
    short rep = 0;

    for(unsigned short e = 1; e < l-1; e++)     // Одним swap-ом ставит на первую позицию в массиве минимальное число
    {
        if(B[0] > B[e])
        {
            rep = B[0];
            B[0] = B[e];
            B[e] = rep;
        }
    }

    return B[0];  
}