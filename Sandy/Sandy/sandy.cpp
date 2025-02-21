#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, ans;         // n: �ʺ�����, ans: ��¼�Ϸ��ķ��÷�������
const int N = 15;
int vis[N][N];      // vis[i][j] ��ʾλ�� (i,j) �����ٸ��ʺ�ռ�ݻ��ܵ�����

// dfs ���������ڵݹ鳢�Է��ûʺ�
// dep: ��ǰ���ڷ��õ� dep ���ʺ�
void dfs(int dep)
{
    // ��� dep == n + 1��˵���Ѿ��ɹ������� n ���ʺ�
    if (dep == n + 1)
    {
        ans++;    
        return;   // ������һ��ݹ�
    }

    // ������ǰ�е�ÿһ�У����Է��ûʺ�
    for (int i = 1; i <= n; i++)
    {
        // �����ǰλ���Ѿ���ռ�ݻ��ܵ�����������
        if (vis[dep][i]) continue;

        // �޸�״̬�����ûʺ󣬲�����乥����Χ
        // 1. ��ǵ�ǰ��
        for (int _i = 1; _i <= n; _i++) vis[_i][i]++;
        // 2. ������϶Խ���
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; _i--, _j--) vis[_i][_j]++;
        // 3. ������¶Խ���
        for (int _i = dep, _j = i; _i <= n && _j >= 1; _i++, _j--) vis[_i][_j]++;
        // 4. ������϶Խ���
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; _i--, _j++) vis[_i][_j]++;
        // 5. ������¶Խ���
        for (int _i = dep, _j = i; _i <= n && _j <= n; _i++, _j++) vis[_i][_j]++;

        // �ݹ������һ���ʺ�
        dfs(dep + 1);

        // �ָ��ֳ�������ʱ������ǰ�ʺ�ķ��ú͹�����Χ���
        // 1. ������ǰ�еı��
        for (int _i = 1; _i <= n; _i++) vis[_i][i]--;
        // 2. �������϶Խ��߱��
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; _i--, _j--) vis[_i][_j]--;
        // 3. �������¶Խ��߱��
        for (int _i = dep, _j = i; _i <= n && _j >= 1; _i++, _j--) vis[_i][_j]--;
        // 4. �������϶Խ��߱��
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; _i--, _j++) vis[_i][_j]--;
        // 5. �������¶Խ��߱��
        for (int _i = dep, _j = i; _i <= n && _j <= n; _i++, _j++) vis[_i][_j]--;
    }
}

int main()
{
    cin >> n;

    // ���� dfs �������ӵ� 1 ���ʺ�ʼ����
    dfs(1);

    cout << ans << '\n';

    return 0;
}
