#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    // 每次挑选当前数组中最大的那个数，然后减半直到数组和减少到一半为止
    int halveArray(vector<int>& nums) {
        // 创建一个最大堆（优先队列），用于存储数组中的数，方便快速获取最大值
        priority_queue<double> heap;

        double sum = 0;    // 用于计算数组的总和

        // 遍历数组中的每个数
        for (int num : nums)
        {
            // 将当前数加入堆中
            heap.push(num);

            // 计算总和
            sum += num;
        }

        // 计算需要减少的目标值
        sum /= 2.0;

        // 计数
        int count = 0;

        while (sum > 0)
        {
            // 取出堆中的最大数，并将其减半
            double t = heap.top() / 2.0;

            // 将最大数从堆中移除
            heap.pop();

            // 将减半后的数重新加入堆中
            heap.push(t);

            // 从需要减少的总和中减去减半后的值
            sum -= t;

            count++;
        }

        // 返回操作次数
        return count;
    }
};
