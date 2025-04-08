#include<iostream>
using namespace std;
const int N = 1e5 + 9;
int cnt[26] = { 0 };
int n;
char s[N], ret[N];

int main()
{
    cin >> n >> s;
    char maxChar = 0;
    int maxCount = 0;
    // �ҳ����ִ��������ַ����Լ���Ӧ�ĸ���
    for (int i = 0; i < n; i++)
    {
        int index = s[i] - 'a';
        if (++cnt[index] > maxCount)
        {
            maxChar = s[i];
            maxCount = cnt[index];
        }
    }

    // �ж��ܲ�������
    if (maxCount > (n + 1) / 2) cout << "no" << endl;
    else
    {
        cout << "yes" << endl;
        int i = 0;
        // �ȴ�����ִ��������ַ�
        while (maxCount--)
        {
            ret[i] = maxChar;
            i += 2;
        }
        // ����ʣ�µ��ַ�
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] && j + 'a' != maxChar)
            {
                while (cnt[j]--)
                {
                    if (i >= n) i = 1;
                    ret[i] = j + 'a';
                    i += 2;
                }
            }
        }
    }
    // ������ź���ַ���
    for (int j = 0; j < n; j++) cout << ret[j];
    cout << '\n';
    return 0;
}
