// test.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>

#include "HDUOJUtils.h"

// test for HDU1002
int randdom(int start, int end)
{
    return rand() % (end - start) + start;
}
void createRandStrNum(char *s1, char *s2)
{
    srand((unsigned)time(NULL));
    int nS1Len = randdom(1, 1000), nS2Len = randdom(1, 1000);
    s1[0] = randdom(0, 9) + '0', s2[0] = randdom(0, 9) + '0';
    for (int i = 1; i < nS1Len; i++)
        s1[i] = randdom(0, 9) + '0';
    for (int j = 1; j < nS2Len; j++)
        s2[j] = randdom(0, 9) + '0';
}
void test_hdu1002()
{
    HDU1002 hdu1002;
    FILE *file = fopen("./HDUOJ/log.txt", "w");
    for (int i = 0; i < 100000; i++)
    {
        char s1[1001] = {0}, s2[1001] = {0}, szRet1[1002] = {0}, szRet2[1002] = {0};
        createRandStrNum(s1, s2);
        hdu1002.stringSum(s1, s2, szRet1);

        hdu1002.reversal_AC(s1);
        hdu1002.reversal_AC(s2);
        hdu1002.stringSum_AC(s1, s2, szRet2);
        hdu1002.reversal_AC(s1);
        hdu1002.reversal_AC(s2);
        hdu1002.reversal_AC(szRet2);

        if(strcmp(szRet1, szRet2) != 0)
        fprintf(file, "%s %s\n", s1, s2);
    }
    fclose(file);
}

int main()
{
    test_hdu1002();
}
