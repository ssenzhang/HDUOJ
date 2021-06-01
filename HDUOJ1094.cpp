//
#include<iostream>

int main()
{
    int N = 0;
    while(std::cin >> N)
    {
        int sum = 0, a = 0;
        while(N--)
        {
            std::cin >> a;
            sum += a;
        }
        std::cout << sum << "\n";
    }
}