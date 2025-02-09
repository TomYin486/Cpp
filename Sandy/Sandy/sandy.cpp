#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>       
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);   // �Ż��������

    int m;  
    cin >> m;    // ����������� m

    // �����������У�V ��ʾ VIP ���ڶ��У�N ��ʾ��ͨ���ڶ���
    queue<string> V, N;

    // ���� m �β���
    while (m--)
    {
        string op;  // op ��ʾ��������
        cin >> op;  

        if (op == "IN")   // ����� "IN"����ʾ���û��������
        {
            string name, q;    //  name ��ʾ�û�����q ��ʾ��������
            cin >> name >> q;  

            // ����� VIP ����
            if (q == "V")  
            {
                V.push(name);  // ���û����� VIP ����
            }
            else  
            {
                // ���������ͨ����
                N.push(name); 
            }
        }
        else  // ����� "OUT"����ʾ���û��뿪����
        {
            string q;  
            cin >> q;  

            if (q == "V")  
            {
                // VIP ���ж�ͷ�û��뿪
                V.pop();  
            }
            else  
            {
                // ��ͨ���ж�ͷ�û��뿪
                N.pop();  
            }
        }
    }

    // ��� VIP �����е������û�
    while (V.size())  
    {
        cout << V.front() << '\n';  
        V.pop();  
    }

    // �����ͨ�����е������û�
    while (N.size())  
    {
        cout << N.front() << '\n';  
        N.pop();  
    }

    return 0;  
}
