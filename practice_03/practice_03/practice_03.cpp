#include<iostream>
using namespace std;
string s;
bool vis[110][26];  // ��¼ÿ���ַ���������Щ��ĸ

// ��������ַ����Ƿ��й�����ĸ
bool check(int left, int right) {
    for (int i = 0; i < 26; i++) {  
        // �ж� left �� right �����ַ����Ƿ񶼰�����ĸ i
        if (vis[left][i] && vis[right][i])  return true;
    }
    return false;
}

int main() {
    int t = 0; cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));  // �ǵ� vis ����Ҫ��ʼ��Ϊ 0
        int n = 0; cin >> n;

        // ����ÿ���ַ���
        for (int i = 0; i < n; i++) {
            cin >> s;  
            for (auto& ch : s) {
                vis[i][ch - 'a'] = true;
            }
        }

        int left = 0, right = n - 1;
        while (left < right) {
            // ��鵱ǰ����λ�õ��ַ����Ƿ��й�����ĸ
            if (!check(left, right)) break;
            left++; right--;
        }
        
        if (right - left > 0)  cout << "No" << '\n';
        else  cout << "Yes" << '\n';
    }
    return 0;
}
