// HDU1004 Let the Balloon Rise
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

void method1();
void method2();

int main()
{
    //method1();
    method2();
}
void method2()
{
    int T = 0;
    while (std::cin >> T && T != 0)
    {
        std::map<std::string, int> map;
        for (int i = 0; i < T; i++)
        {
            std::string str;
            std::cin >> str;
            std::map<std::string, int>::iterator iter = map.find(str);
            if (iter != map.end())
                iter->second = iter->second + 1;
            else
                map.insert(std::pair<std::string, int>(str, 1));
        }
        using tp = decltype(map)::value_type;
        std::cout << std::max_element(map.begin(), map.end(), [](const tp &p1, const tp &p2){
            return p1.second < p2.second;
        })->first << "\n";
    }
}

void method1()
{
    int T = 0;
    while (std::cin >> T && T != 0)
    {
        std::map<std::string, int> map;
        for (int i = 0; i < T; i++)
        {
            std::string str;
            std::cin >> str;
            std::map<std::string, int>::iterator iter = map.find(str);
            if (iter != map.end())
                iter->second = iter->second + 1;
            else
                map.insert(std::pair<std::string, int>(str, 1));
        }

        // 别排序了，去找遍历map找最大的；大佬构建字典树统计。。。
        std::vector<std::pair<std::string, int>> vec;
        std::map<std::string, int>::iterator iter = map.begin();
        for (; iter != map.end(); iter++)
            vec.push_back(*iter);
        std::sort(vec.begin(), vec.end(), [](std::pair<std::string, int> &lp, std::pair<std::string, int> &rp)
                  { return lp.second > rp.second; });

        std::cout << vec[0].first << "\n";
    }
}