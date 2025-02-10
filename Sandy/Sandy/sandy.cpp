#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>   
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 优化，将所有的整数转换为字符串
        vector<string> strs;
        for (int x : nums)
        {
            strs.push_back(to_string(x));
        }

        // 排序
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2)
            {
                // 如果 s1 + s2 > s2 + s1，则 s1 排在 s2 前面
                return s1 + s2 > s2 + s1;
            });

        // 将排序后的字符串拼接成最终的结果
        string ret;
        for (auto& s : strs)
        {
            ret += s;
        }

        // 如果结果的第一个字符是 '0'，说明所有数字都是 0，直接返回 "0"
        if (ret[0] == '0')
        {
            return "0";
        }

        // 返回拼接后的最大数
        return ret;
    }
};
