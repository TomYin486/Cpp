#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 120;       // 花园的最大尺寸
bool a[N][N], b[N][N];   // 花园的灌溉状态

int main()
{
    int n, m; cin >> n >> m;    // 花园的行数和列数

    int t; cin >> t;            // 输入出水管的数量
    for (int i = 1; i <= t; i++)
    {
        // 输入每个出水管的坐标
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;      // 在数组 a 中标记出水管的位置
    }

    int k; cin >> k;       // 灌溉的分钟数

    // 循环 k 次，模拟每分钟的灌溉过程
    while (k--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1) // 如果当前位置已经被灌溉
                {
                    // 将当前位置的上下左右四个方向标记为已灌溉
                    b[i][j] = b[i - 1][j] = b[i + 1][j] = b[i][j - 1] = b[i][j + 1] = 1;
                }
            }
        }

        // 将 b 数组的灌溉状态复制到 a 数组，以便下一分钟的扩展
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = b[i][j];
            }
        }
    }

    // 计算最终被灌溉的方格数量
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 如果当前位置被灌溉，增加计数
            if (a[i][j] == 1)
            {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
