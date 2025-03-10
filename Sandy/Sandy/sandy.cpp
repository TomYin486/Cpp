#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// L: ��㵽�յ�ľ��룬n: ��ʯ������m: ���������ߵ���ʯ����
int L, n, m; 
const int N = 1e5; 
int stone[N];   // ÿ����ʯ��λ��

// �ж��Ƿ���������߲����� m ����ʯ������£�ʹ�������Ծ��������Ϊ step
bool check(int step)
{
    int pos = 0; 
    int cnt = 0;  // ��Ҫ���ߵ���ʯ����
    for (int i = 1; i <= n + 1; i++) 
    {
        // �����ǰ��ʯ����һ����ʯ�ľ���С�� step����Ҫ���������ʯ
        if (stone[i] - stone[pos] < step) cnt++;
        else pos = i;  // ���������ʯ
    }

    // ���ߵ���ʯ�������� m
    if (cnt > m) return false; 
    return true; 
}

int main()
{
    cin >> L >> n >> m; 
    stone[n + 1] = L;    // ���յ��λ�ô�����ʯ��������һ��λ��
    for (int i = 1; i <= n; i++)  cin >> stone[i];  
        
    int left, right; 
    left = 0, right = L; 
    // ���ֲ���
    while (left < right) 
    {
        int mid = 0;
        mid = left + (right - left + 1) / 2; 
        if (check(mid)) left = mid;  // ���Ը����ֵ
        else right = mid - 1;  // ���Ը�С��ֵ
    }

    cout << left << '\n'; 
    return 0;
}
