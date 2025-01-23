#define _CRT_SECURE_NO_WARNINGS
#include<iostream>     // 包含标准输入输出库，用于使用 cin 和 cout
#include <algorithm>   // 包含 max_element 和 min_element 所需的头文件
#include<iomanip>      // 包含用于格式化输出的库，如 setprecision
using namespace std;   // 使用标准命名空间，避免 std:: 前缀

const int N = 1e4 + 9;
int a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);  // 优化输入输出，加快执行速度
    int n = 0;
    cin >> n;
    int i = 0;
    long long sum = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // max_element 和 min_element 用于查找给定范围内的最大元素和最小元素的地址
    // a：指向数组起始位置的地址 
    // a + n：指向数组结束位置的地址，查找范围是 [a, a + n)
    cout << *max_element(a, a + n) << '\n';
    cout << *min_element(a, a + n) << '\n';

    // 方法发二
    //int mx = a[0];
    //int mi = a[0];

    // 循环遍历数组，找出最高值和最低值 
    //for (i = 1; i < n; i++)
    //{
    //    mx = max(mx, a[i]);    // 更新最高值
    //    mi = min(mi, a[i]);    // 更新最低值
    //}
    //cout << mx << '\n';
    //cout << mi << '\n';

    //for (i = 0; i < n; i++)
    //{
    //    sum += a[i];
    //}

    // 输出平均分，保留两位小数，注意要乘个 1.0
    cout << fixed << setprecision(2) << 1.0 * sum / n;

    return 0;
}
