#include<iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> cnt;   // ͳ��ÿ������������

bool check(int x)  // �ж��������Ϊ x ʱ���ܷ�ֳ� m ��
{
    int g = 0;  // �ֳܷɶ�����
    // ����ߵ� C++ �汾
    /*for (auto& [a, b] : cnt)
    {
        g += b / x + (b % x != 0 ? 1 : 0);
    }*/

    for (auto& item : cnt) {
        int a = item.first;   // ��
        int b = item.second;  // ֵ
        g += b / x + (b % x != 0 ? 1 : 0);
    }
    return g <= m;
}

int main()
{
    cin >> n >> m;
    int hmax = 0;   // ͳ��������������
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        hmax = max(hmax, ++cnt[x]);
    }

    int kinds = cnt.size();
    // ����߽���� 
    if (kinds > m) cout << -1 << '\n';
    else {
        // ����ö��
        //for(int i = 1; i <= hmax; i++)  // ö�����е��������
        //{
        //    if(check(i)){
        //        cout << i << '\n';
        //		break;
        //    }
        //}
        // ���ֽⷨ
        int l = 1, r = hmax;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
