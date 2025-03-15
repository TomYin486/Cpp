#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];     // �ڽӱ��洢���ɵĹ�ϵ
int siz[N];           // siz[x] ��ʾ�� x Ϊ���ڵ�������Ĵ�С���൱�� x ����������

struct Node
{
    int siz, id;   // siz ��ʾ����������id ��ʾ���ڵ����

    // ����
    bool operator<(const Node& u) const
    {
        return siz == u.siz ? id < u.id : siz > u.siz;
    }
};

vector<Node> v;    // �洢���а��ڵ���Ϣ

// ������ x Ϊ���ڵ��������С(��������)
void dfs(int x, int p)
{
    siz[x] = 1;        // ��ʼ����ǰ�ڵ����������Ϊ 1���Լ���
    for (const auto& y : g[x])  // ���� x �������ӽڵ�
    {
        if (y == p) continue;  // �������ڵ�
        dfs(y, x);             // �����ӽڵ��������������ǰ y �ĸ��ڵ�Ϊ x 
        siz[x] += siz[y];
    }
}

int main()
{
    int n, m; cin >> n >> m;  // ������������� n ��С������� m

    // ������ɵĹ�ϵ��
    for (int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        g[y].push_back(x);  // �� x ��ӵ� y ���ӽڵ���
    }

    // �Ӹ��ڵ� 1 ��ʼ������ÿ���ڵ����������
    dfs(1, 0);

    // �����а��ڵ���Ϣ�洢������ v ��
    for (int i = 1; i <= n; ++i)
        v.push_back({ siz[i] - 1, i });  // siz[i] - 1 ��ʾ��ȥ�Լ������������

    // �������������Ӵ�С�����������������ͬ����Ŵ�С��������
    sort(v.begin(), v.end());

    // ���������Ľ�����ҵ�С��������
    for (int i = 0; i < v.size(); ++i)
        if (v[i].id == m)
            cout << i + 1 << '\n';  // �������

    return 0;
}
