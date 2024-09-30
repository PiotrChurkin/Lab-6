#include <iostream>

int main()
{
    int N = 0;

    std::cin >> N;
    int A[1000] = {0};
    int B[1000] = {0};

    bool e = 0;
    short t = 0;
    short k = 0;

    for(int i = 0; i < N; i++)
    {
        e = 0;
        std::cin >> A[i];
        B[i] = A[i];
        t = B[i]%10;
        while(B[i]!=0)
        {
            if(B[i]%10==t)
                e=1;

            if(e==0)
                break;
            
            B[i] = B[i]/10;
        }

        if(e==1)
            k=k+1;
    }

    int replacement = 0;

    if(k>=3)
    {

        for(int i = 0; i <= N-2; i++)
        {
            for(int j = 1; j <= N-1; j++)
            {
                if(A[i] < A[j])
                {
                    replacement = A[i];
                    A[i] = A[j];
                    A[j] = replacement;
                }
            }

        }
    }

    std::cout << "//////////////////" << std::endl;

    for(int i = 0; i < N; i++)
    {
        std::cout << A[i] << std::endl;
    }

    return 0;
}


