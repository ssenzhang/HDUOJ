//
#include<iostream>

int main()
{
    int a = 0, b = 0;
    while(std::cin >> a >> b)
    {
        if(a == 0 && b == 0)
            break;
        std::cout << a + b << "\n";
    }
}