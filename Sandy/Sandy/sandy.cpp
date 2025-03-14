#include<iostream>
using namespace std;
using ll = long long;  
const int N = 105;        
const ll p = 1e6 + 7;  

ll a[N], dp[N][N];    // dp[i][j] ��ʾʹ��ǰ i �ֻ����ڷ� j �軨�ķ�����
int main() 
{
    int n, m; cin >> n >> m;    // n Ϊ��������m Ϊ������
    
    for (int i = 1; i <= n; i++) cin >> a[i];  

    // û�л�ʱ���ڷ� 0 �軨�ķ�����Ϊ 1
    dp[0][0] = 1;  

    // ����ÿ�ֻ��İڷŷ�����
    for (int i = 1; i <= n; i++) 
    {  // ����ÿ�ֻ�
        for (int j = 0; j <= m; j++) 
        {  // �����ڷŵ�����
            for (int k = 0; k <= a[i] && k <= j; k++) 
            {   // ����ǰ�����԰ڷŵ�����
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;  
            }
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}
