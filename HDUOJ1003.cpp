// HDU1003 Max Sum
#include<iostream>

int maxSum(const int *arr, const int nLen, int &start, int &end);

int main()
{
    int T = 0;
    std::cin >> T;
    for(int i = 0; i < T; i++)
    {
        int nLen = 0, arr[100000] = { 0 }, start = 0, end = 0;
        std::cin >> nLen; 
        for(int j = 0; j < nLen; j++)
            std::cin >> arr[j];
        
        std::cout << "Case " << i + 1 << ":\n";
        std::cout << maxSum(arr, nLen, start, end) << " " << start + 1 << " " << end + 1<< "\n";
        if(i < T - 1)
            std::cout << "\n";
    }

    system("pause");
}

int maxSum(const int *arr, const int nLen, int &start, int &end)
{
    // fun[n] = max{fun(n-1), fun(n-1)+arr[n-1], arr[n-1]}
    int dp[100000] = { 0 };
    dp[0] = arr[0], start = 0, end = 0;
    for(int i = 1; i < nLen; i++)
    {
        if(arr[i] < 0)
        {
            if(dp[i - 1] < arr[i])
                dp[i] = arr[i], start = i, end = i;
            else
                dp[i] = dp[i - 1], end = i - 1;
        }
        else if(arr[i] > 0)
        {
            if(dp[i - 1] < 0)
                dp[i] = arr[i], start = i, end = i;
            else if(dp[i - 1] > 0)
                dp[i] = dp[i - 1] + arr[i], end = i;
            else 
                dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp[nLen - 1];
}