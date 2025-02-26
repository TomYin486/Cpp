#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using ll = long long;  
const ll N = 1e6 + 9, p = 1e9 + 7;  // N �������С��p ��ģ��
ll dp[N], prefix[N];  

int main()
{
    int n, k;
    cin >> n >> k;  // n �ǿ�λ����k ����Ͱ֮����Ҫ����С��λ��

    // dp[0] �� prefix[0] ��ʼ��Ϊ 1����ʾû�п�λʱ�ķ�����Ϊ 1
    // dp[i] ��ʾ��λ�� i ��β�ķ�������
    dp[0] = prefix[0] = 1;  

    // �� dp ����ÿ��λ�õķ�����
    for (int i = 1; i <= n; i++)
    {
        // �����ǰλ�� i ��ȥ k - 1 С�� 0��˵���޷�������Ͱ��������Ϊ 1
        if (i - k - 1 < 0)
        {
            dp[i] = 1;
        }
        else
        {
            // prefix[i - k - 1] ��ʾ�� i - k - 1 λ��֮ǰ�ķ�����
            dp[i] = prefix[i - k - 1];
        }
           
        // ���� prefix ����
        prefix[i] = (prefix[i - 1] + dp[i]) % p;  
    }

    cout << prefix[n] << '\n';
    return 0;
}
