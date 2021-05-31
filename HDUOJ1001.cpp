#include<iostream>

int main()
{
    int N = 0;
    while(std::cin>>N)
    {
        if(N % 2 == 0)
            std::cout << N / 2 * (1 + N) << "\n\n";
        else
            std::cout << (1 + N) / 2 * N << "\n\n";
    }
}