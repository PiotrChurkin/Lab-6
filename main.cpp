#include <iostream>

bool MultiplicityOfSumOfDigits(int x);
bool quantityOfRecurringDigits(int x);

int main()
{
    int A[20000] = {0};
    unsigned short N = 0;
    int Element = 0;
    

    std::cin >> N;

    unsigned short iter = N;

    if(N > 10000)
    {
        std::cout << "Error!!!";
        return 0;
    }

    for(unsigned short i = 0; i<N; i++)
    {
        std::cin >> A[i];   
    }

    for(unsigned short i = 0; i < N; i++)
    {
        if(MultiplicityOfSumOfDigits(A[i]))
        {
            for(unsigned short k = i; k < N-1; k++)
            {
                A[k] = A[k+1];
            }
            iter = iter - 1;
        }
        else if(quantityOfRecurringDigits(A[i]))
        {
            for(unsigned short j = N; j > (i+1); j--)
            {
                A[j] = A[j-1];
            }
            A[i+1] = A[i];
            iter = iter + 2;
        }
        else
        {
            iter = iter + 1;
        }
    }


    for(unsigned short i = 0; i < iter; i++)
    {
        std::cout << A[i] << "\t";
    }



    return 0;
}

bool MultiplicityOfSumOfDigits(int x) 
{
    int number = abs(x);
    unsigned short sumOfDigits = 0;

    while(number!=0)
    {
        sumOfDigits = sumOfDigits + number%10;
        number = number / 10;
    }

    return (sumOfDigits%7==0);
}

bool quantityOfRecurringDigits(int x)
{
    int number = abs(x);
    int B[20] = {0};
    unsigned short lenght = 0;

    for(unsigned short i = 0; number!=0; i++)
    {
        B[i] = number%10;
        number = number / 10;
        lenght = lenght + 1;
    }

    int k = 0;

    for(unsigned short i = 0; i < lenght-1; i++)
    {
        for(unsigned short j = i+1; j < lenght; j++)
        {
            if(B[i]==B[j])
                k+=1;
        }
    }

    return (k!=0);
}