// 
#include<iostream>

int main()
{
    int k = 0;
    while(std::cin >> k)
    {
        int a = 1;
        for(a = 1; a < 65; a++)
        {
            if((k * a + 18) % 65 ==0)
                break;
        }
        if(a < 65)
            std::cout << a << "\n";
        else
            std::cout << "no\n";
    }
}