#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    // 尽可能优先使用大面额的钞票进行找零，以确保手头的零钱能够满足后续顾客的需求以及更新零钱数量
    bool lemonadeChange(vector<int>& bills) {
        // 记录 5 元跟 10 元的张数
        int five = 0;
        int ten = 0;

        // 遍历每个顾客支付的钞票
        for (auto x : bills)
        {
            // 如果顾客支付 5 元，直接收下，不需要找零
            if (x == 5) five++;

            // 如果顾客支付 10 元，需要找 5 元
            else if (x == 10)
            {
                // 如果没有 5 元，无法找零，返回 false
                if (five == 0) return false;
                five--;
                ten++;
            }
            else
            {
                // 如果顾客支付 20 元，需要找 15 元
                // 贪心: 优先使用 10 元和 5 元的组合找零
                if (five != 0 && ten != 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
