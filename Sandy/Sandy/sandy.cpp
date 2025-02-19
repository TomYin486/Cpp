#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 2e5 + 9;
int a[N];

// 利用快慢指针，保持区间 [i,j] 中 >= m 的个数至少有 k 个，且区间尽可能小
// 得到区间 [i,j] 后，对于这个左端点，有 n - j + 1 个右段点可取
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // 优化输入输出
    int n, m, k;
    cin >> n >> m >> k;

    // 得到数组 a
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;    // 表示满足条件的子串数量

    // 使用双指针 i 和 j 来遍历数组
    // cnt 用于记录当前子串中大于等于 m 的元素数量
    for (int i = 1, j = 0, cnt = 0; i <= n; i++)
    {
        // 移动 j 指针，直到当前子串中有至少 k 个元素大于等于 m
        while (i > j || (j + 1 <= n && cnt < k))
        {
            j++;
            cnt += (a[j] >= m);   // 如果 a[j] >= m，则 cnt 增加
        }

        // 如果满足条件，则计算从当前子串开始到数组末尾的所有可能的子串数量
        if (cnt >= k)
        {
            ans += n - j + 1;
        }

        // 移动 i 指针，减少 cnt 中相应的计数
        cnt -= (a[i] >= m);
    }

    cout << ans << '\n';
    return 0;
}
