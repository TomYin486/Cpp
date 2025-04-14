#include<iostream>
using namespace std;
string s;
bool vis[110][26];  // 记录每个字符串包含哪些字母

// 检查两个字符串是否有公共字母
bool check(int left, int right) {
    for (int i = 0; i < 26; i++) {  
        // 判断 left 和 right 两个字符串是否都包含字母 i
        if (vis[left][i] && vis[right][i])  return true;
    }
    return false;
}

int main() {
    int t = 0; cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));  // 记得 vis 数组要初始化为 0
        int n = 0; cin >> n;

        // 处理每个字符串
        for (int i = 0; i < n; i++) {
            cin >> s;  
            for (auto& ch : s) {
                vis[i][ch - 'a'] = true;
            }
        }

        int left = 0, right = n - 1;
        while (left < right) {
            // 检查当前左右位置的字符串是否有公共字母
            if (!check(left, right)) break;
            left++; right--;
        }
        
        if (right - left > 0)  cout << "No" << '\n';
        else  cout << "Yes" << '\n';
    }
    return 0;
}
