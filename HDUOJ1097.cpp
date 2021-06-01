//
#include <iostream>
#include <set>

int arr[10][10];
int power(int a, int b);

int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::set<int> tmpSet;
        for (int j = 1; j < 1000; j++)
        {
            int digit = power(i, j) % 10;
            if (tmpSet.empty())
            {
                arr[i][0] = digit;
                tmpSet.insert(digit);
            }
            else if (tmpSet.find(digit) != tmpSet.end())
                break;
            else
            {
                arr[i][tmpSet.size()] = digit;
                tmpSet.insert(digit);
            }
        }
        arr[i][9] = tmpSet.size();
    }

    int a = 0, b = 0;
    while (std::cin >> a >> b)
    {
        std::cout << arr[a % 10][b % arr[a % 10][9] == 0 ? arr[a % 10][9] - 1 : b % arr[a % 10][9] - 1] << "\n";
    }
}

int power(int a, int b)
{
    if (b == 0) 
        return 1;
    if (b % 2 == 0)
        return power(a, b / 2) * power(a, b / 2);
    else
        return power(a, b / 2) * power(a, b / 2) * a;
}