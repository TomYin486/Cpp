#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    // ����������ʹ�ô����ĳ�Ʊ�������㣬��ȷ����ͷ����Ǯ�ܹ���������˿͵������Լ�������Ǯ����
    bool lemonadeChange(vector<int>& bills) {
        // ��¼ 5 Ԫ�� 10 Ԫ������
        int five = 0;
        int ten = 0;

        // ����ÿ���˿�֧���ĳ�Ʊ
        for (auto x : bills)
        {
            // ����˿�֧�� 5 Ԫ��ֱ�����£�����Ҫ����
            if (x == 5) five++;

            // ����˿�֧�� 10 Ԫ����Ҫ�� 5 Ԫ
            else if (x == 10)
            {
                // ���û�� 5 Ԫ���޷����㣬���� false
                if (five == 0) return false;
                five--;
                ten++;
            }
            else
            {
                // ����˿�֧�� 20 Ԫ����Ҫ�� 15 Ԫ
                // ̰��: ����ʹ�� 10 Ԫ�� 5 Ԫ���������
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
