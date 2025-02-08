#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>     // 用于使用 strlen
using namespace std;

// 将 L 看做 1，Q 看做 -1，只有当某个区间的和为 0 时，字符串是平衡的
// 可以预处理出前缀和，然后枚举所有区间（这一步的时间复杂度是 O(n ^ 2)的），得到所有平衡区间的长度最后取大输出

const int N = 1010;   // 数组的最大大小  
char s[N];            // 用于输入的字符串  
int prefix[N];        // 存储前缀和数组  

int main()
{
    cin >> s + 1;            // 从下标 1 开始输入字符串
    int n = strlen(s + 1);   // 计算字符串的长度

    int i = 0;
    int j = 0;
    prefix[0] = 0;

    // 计算前缀和数组，'L' 对应 +1，'Q' 对应 -1
    for (i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + (s[i] == 'L' ? 1 : -1);
    }

    int ans = 0;         // 表示最长平衡串的长度

    // 遍历所有可能的子串，检查是否为平衡串
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            // 如果前缀和差为 0，则子串中 'L' 和 'Q' 的数量相等
            if (prefix[j] - prefix[i - 1] == 0)
            {
                ans = max(ans, j - i + 1);      // 更新最长平衡串的长度
            }
        }
    }

    cout << ans << '\n';      // 输出最长平衡串的长度

    return 0;
}
