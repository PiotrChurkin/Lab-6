#include <iostream>

int main()
{
    int N = 0;

    std::cin >> N;
    int A[1000] = {0};
    int B = 0;

    bool e = 0;
    int t = 0;
    unsigned short k = 0;

    for(short i = 0; i < N; i++)
    {
        e = 0;

        std::cin >> A[i];       // Считывает число в консоли

        B = abs(A[i]);
        t = B%10;

        while(B!=0)     // Если в числе все цифры одинаковы, то возвращает e = True
        {
            if(B%10==t)
                e = 1;
            else
                e = 0;

            if(!e)
                break;
            
            B = B/10;
        }

        if(e)
            k=k+1;
    }

    int replacement = 0;

    if(k>=3)    // Если количество чисел, в которых все цифры одинаковы, больше 3, то производится сортировка массива swap-ом
    {

        for(unsigned short i = 0; i < N-1; i++)
        {
            for(unsigned short j = i+1; j < N; j++)
            {
                if(A[i] < A[j])
                {
                    replacement = A[i];
                    A[i] = A[j];
                    A[j] = replacement;
                }
            }

        }
        std::cout << "SWAP sorting was complated" ;
    }
    else
        std::cout << "SWAP sorting wasn't complated" ;

    std::cout << "//////////////////" << std::endl;

    for(unsigned short i = 0; i < N; i++)      // Выводит массив
    {
        std::cout << A[i] << std::endl;
    }

    return 0;
}