#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>   
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // �Ż��������е�����ת��Ϊ�ַ���
        vector<string> strs;
        for (int x : nums)
        {
            strs.push_back(to_string(x));
        }

        // ����
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2)
            {
                // ��� s1 + s2 > s2 + s1���� s1 ���� s2 ǰ��
                return s1 + s2 > s2 + s1;
            });

        // ���������ַ���ƴ�ӳ����յĽ��
        string ret;
        for (auto& s : strs)
        {
            ret += s;
        }

        // �������ĵ�һ���ַ��� '0'��˵���������ֶ��� 0��ֱ�ӷ��� "0"
        if (ret[0] == '0')
        {
            return "0";
        }

        // ����ƴ�Ӻ�������
        return ret;
    }
};
