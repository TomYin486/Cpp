#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 1e5 + 9;   // �������󳤶�
int a[N];            

// ���ÿ���ָ�룬�������� [i, j] ������С�Һ� >= S
// �� [i, j] �е� sum >= S �������� j û�����壬���� i, j ������
// �� i ����� sum ���� < S����ʱ j ���������ƣ�����ֻ�����ƣ����� i, j ��ֻ�����ƣ��Ӷ���������

int main()
{
    // �������������
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, S;         // n �����г��ȣ�S ��Ŀ�������
    cin >> n >> S;    

    int i = 0;
    // ��ȡ�����е�Ԫ��
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = n + 1;   // ans Ϊ n + 1����ʾһ�������ܵĳ��ȣ����ں����ж�
    int j = 0;
    int sum = 0;

    // ˫ָ��
    for (i = 1; i <= n; i++)
    {
        // ָ�� j �����ƶ���ֱ������� sum >= S ���� j ������Χ
        while (i > j || (j + 1 <= n && sum < S))
        {
            j++;           // ��ָ������
            sum += a[j];   // �ۼ������
        }

        // �����ǰ����� sum >= S������ ans Ϊ��ǰ����ĳ��Ⱥ� ans �еĽ�Сֵ
        if (sum >= S)
        {
            ans = min(ans, j - i + 1);
        }

        // �ƶ���ָ�� i������ sum �м�ȥ a[i]���Ա����Ѱ�Ҹ��̵�����
        sum -= a[i];
    }

    // ��� ans ��Ȼ���� n����ʾû���ҵ��������������䣬��� 0��������� ans
    cout << (ans > n ? 0 : ans) << '\n';

    return 0; 
}
