// HDU1002 A + B Problem II
#include <iostream>
#include <cstring>
#include <string>

char* stringSum(const char *s1, const char *s2, char *nRet);
char charSum(const char c1, const char c2, char &carry);
char* reverseStr(char *s);

int main()
{
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        char s1[1001] = {0}, s2[1001] = {0}, szRet[1002] = {0};
        std::cin >> s1 >> s2;
        std::cout << "Case " << i + 1 << ":\n";
        std::cout << s1 << " + " << s2 << " = " << stringSum(s1, s2, szRet) << "\n";
        if (i < N - 1)
            std::cout << "\n";
    }
}

char *stringSum(const char *s1, const char *s2, char *szRet)
{
    int len1 = strlen(s1), len2 = strlen(s2), i = 0, j = 0, k = 0;
    char carry = '0';

    for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--, k++)
        szRet[k] = charSum(s1[i], s2[j], carry);
    for (; i >= 0; i--, k++)
        szRet[k] = charSum(s1[i], '0', carry);
    for (; j >= 0; j--, k++)
        szRet[k] = charSum(s2[j], '0', carry);
    if (carry != '0')
        strcat(szRet, "1");

    return reverseStr(szRet);
}

char *reverseStr(char *s)
{
    int nLen = strlen(s);
    for (int i = 0; i < nLen / 2; i++)
    {
        char temp = s[i];
        s[i] = s[nLen - i - 1];
        s[nLen - i - 1] = temp;
    }

    return s;
}

char charSum(const char c1, const char c2, char &carry)
{
    int sum = (c1 - '0') + (c2 - '0') + (carry - '0');
    carry = sum / 10 + '0';
    return sum % 10 + '0';
}
