#include<iostream>
using namespace std;
using ll = long long;  
const int N = 105;        
const ll p = 1e6 + 7;  

ll a[N], dp[N][N];    // dp[i][j] 表示使用前 i 种花，摆放 j 盆花的方案数
int main() 
{
    int n, m; cin >> n >> m;    // n 为花种数，m 为总盆数
    
    for (int i = 1; i <= n; i++) cin >> a[i];  

    // 没有花时，摆放 0 盆花的方案数为 1
    dp[0][0] = 1;  

    // 计算每种花的摆放方案数
    for (int i = 1; i <= n; i++) 
    {  // 遍历每种花
        for (int j = 0; j <= m; j++) 
        {  // 遍历摆放的盆数
            for (int k = 0; k <= a[i] && k <= j; k++) 
            {   // 计算前花可以摆放的盆数
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;  
            }
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}
