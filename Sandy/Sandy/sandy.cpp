#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>       
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);   // 优化输入输出

    int m;  
    cin >> m;    // 输入操作次数 m

    // 创建两个队列，V 表示 VIP 窗口队列，N 表示普通窗口队列
    queue<string> V, N;

    // 处理 m 次操作
    while (m--)
    {
        string op;  // op 表示操作类型
        cin >> op;  

        if (op == "IN")   // 如果是 "IN"，表示有用户进入队列
        {
            string name, q;    //  name 表示用户名，q 表示队列类型
            cin >> name >> q;  

            // 如果是 VIP 窗口
            if (q == "V")  
            {
                V.push(name);  // 将用户加入 VIP 队列
            }
            else  
            {
                // 否则加入普通队列
                N.push(name); 
            }
        }
        else  // 如果是 "OUT"，表示有用户离开队列
        {
            string q;  
            cin >> q;  

            if (q == "V")  
            {
                // VIP 队列队头用户离开
                V.pop();  
            }
            else  
            {
                // 普通队列队头用户离开
                N.pop();  
            }
        }
    }

    // 输出 VIP 队列中的所有用户
    while (V.size())  
    {
        cout << V.front() << '\n';  
        V.pop();  
    }

    // 输出普通队列中的所有用户
    while (N.size())  
    {
        cout << N.front() << '\n';  
        N.pop();  
    }

    return 0;  
}
