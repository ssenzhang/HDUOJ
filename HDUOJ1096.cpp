// 
#include<iostream>

int main()
{
    int T = 0;
    std::cin >> T;
    while(T--)
    {
        int N = 0, sum = 0, a = 0;
        std::cin >> N;
        while(N--)
        {
            std::cin >> a;
            sum += a;
        }  
        std::cout << sum << "\n";
        if(T > 0)
            std::cout << "\n"; 
    }
}