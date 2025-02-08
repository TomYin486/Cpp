#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>     // ����ʹ�� strlen
using namespace std;

// �� L ���� 1��Q ���� -1��ֻ�е�ĳ������ĺ�Ϊ 0 ʱ���ַ�����ƽ���
// ����Ԥ�����ǰ׺�ͣ�Ȼ��ö���������䣨��һ����ʱ�临�Ӷ��� O(n ^ 2)�ģ����õ�����ƽ������ĳ������ȡ�����

const int N = 1010;   // ���������С  
char s[N];            // ����������ַ���  
int prefix[N];        // �洢ǰ׺������  

int main()
{
    cin >> s + 1;            // ���±� 1 ��ʼ�����ַ���
    int n = strlen(s + 1);   // �����ַ����ĳ���

    int i = 0;
    int j = 0;
    prefix[0] = 0;

    // ����ǰ׺�����飬'L' ��Ӧ +1��'Q' ��Ӧ -1
    for (i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + (s[i] == 'L' ? 1 : -1);
    }

    int ans = 0;         // ��ʾ�ƽ�⴮�ĳ���

    // �������п��ܵ��Ӵ�������Ƿ�Ϊƽ�⴮
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            // ���ǰ׺�Ͳ�Ϊ 0�����Ӵ��� 'L' �� 'Q' ���������
            if (prefix[j] - prefix[i - 1] == 0)
            {
                ans = max(ans, j - i + 1);      // �����ƽ�⴮�ĳ���
            }
        }
    }

    cout << ans << '\n';      // ����ƽ�⴮�ĳ���

    return 0;
}
