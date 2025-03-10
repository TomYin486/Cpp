#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// L: 起点到终点的距离，n: 岩石数量，m: 最多可以移走的岩石数量
int L, n, m; 
const int N = 1e5; 
int stone[N];   // 每块岩石的位置

// 判断是否可以在移走不超过 m 块岩石的情况下，使得最短跳跃距离至少为 step
bool check(int step)
{
    int pos = 0; 
    int cnt = 0;  // 需要移走的岩石数量
    for (int i = 1; i <= n + 1; i++) 
    {
        // 如果当前岩石与上一个岩石的距离小于 step，需要移走这块岩石
        if (stone[i] - stone[pos] < step) cnt++;
        else pos = i;  // 跳到这块岩石
    }

    // 移走的岩石数量超过 m
    if (cnt > m) return false; 
    return true; 
}

int main()
{
    cin >> L >> n >> m; 
    stone[n + 1] = L;    // 将终点的位置存入岩石数组的最后一个位置
    for (int i = 1; i <= n; i++)  cin >> stone[i];  
        
    int left, right; 
    left = 0, right = L; 
    // 二分查找
    while (left < right) 
    {
        int mid = 0;
        mid = left + (right - left + 1) / 2; 
        if (check(mid)) left = mid;  // 尝试更大的值
        else right = mid - 1;  // 尝试更小的值
    }

    cout << left << '\n'; 
    return 0;
}
