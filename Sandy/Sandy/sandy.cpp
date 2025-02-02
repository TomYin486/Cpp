#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    // ÿ����ѡ��ǰ�����������Ǹ�����Ȼ�����ֱ������ͼ��ٵ�һ��Ϊֹ
    int halveArray(vector<int>& nums) {
        // ����һ�����ѣ����ȶ��У������ڴ洢�����е�����������ٻ�ȡ���ֵ
        priority_queue<double> heap;

        double sum = 0;    // ���ڼ���������ܺ�

        // ���������е�ÿ����
        for (int num : nums)
        {
            // ����ǰ���������
            heap.push(num);

            // �����ܺ�
            sum += num;
        }

        // ������Ҫ���ٵ�Ŀ��ֵ
        sum /= 2.0;

        // ����
        int count = 0;

        while (sum > 0)
        {
            // ȡ�����е�����������������
            double t = heap.top() / 2.0;

            // ��������Ӷ����Ƴ�
            heap.pop();

            // �������������¼������
            heap.push(t);

            // ����Ҫ���ٵ��ܺ��м�ȥ������ֵ
            sum -= t;

            count++;
        }

        // ���ز�������
        return count;
    }
};
