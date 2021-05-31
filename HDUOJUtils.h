#ifndef _HDUOJUTILS_H_
#define _HDUOJUTILS_H_

#include <cstring>
#include <cstdio>

// HDU1002
struct HDU1002
{
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

    void reversal_AC(char *p)
    {
        int len = strlen(p), i;
        char t;
        for (i = 0; i < len / 2; i++)
        {
            t = p[i];
            p[i] = p[len - 1 - i];
            p[len - 1 - i] = t;
        }
    }
    void stringSum_AC(char *p1, char *p2, char *p3)
    {
        int am, bm, t, i, s;
        for (i = t = 0; p1[i] != '\0' || p2[i] != '\0'; i++)
        {
            if (p1[i] == '\0')
                am = 0;
            else
                am = p1[i] - '0';
            if (p2[i] == '\0')
                bm = 0;
            else
                bm = p2[i] - '0';
            s = am + bm + t;
            p3[i] = s % 10 + '0';
            t = s / 10;
        }
        if (t != 0) //注意可能增多一位
            p3[i] = t + '0';
    }
};

#endif