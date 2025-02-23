#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// ���ַ���ת��Ϊ����
int s2i(string s)
{
	int res = 0;
	for (const auto& i : s)
	{
		res = res * 10 + i - '0';
	}
	return res;
}

// ������ת��Ϊ�ַ�������ȷ���ַ����ĳ���Ϊ w
string i2s(int x, int w)
{
	string res;
	while (x) res += (x % 10) + '0', x /= 10;
	while (res.length() < w) res += '0';
	reverse(res.begin(), res.end());
	return res;
}

// �ж��Ƿ�������
bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// �ж������Ƿ�Ϸ�
bool isok(int year, int month, int day)
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year))
	{
		days[2] = 29;
	}
	return day <= days[month];
}

// �ж��ַ����Ƿ��ǻ���
bool isPa(string s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

// �ж��ַ����Ƿ��� ABABBABA �͵Ļ���
bool isPa2(string s)
{
	if (!isPa(s))
	{
		return false;
	}
	return s[0] == s[2] && s[1] == s[3];
}

// s2i ���������ַ���ת��Ϊ����
// i2s ������������ת��Ϊ�ַ�������ȷ���ַ����ĳ���Ϊָ������
// isLeapYear �������ж�ĳ���Ƿ�������
// isok �������жϸ������ꡢ�¡����Ƿ���һ���Ϸ�������
// isPa �������ж�һ���ַ����Ƿ��ǻ���
// isPa2 �������ж�һ���ַ����Ƿ��� ABABBABA �͵Ļ���

int main()
{
	string s; cin >> s;
	int year = s2i(s.substr(0, 4)), month = s2i(s.substr(4, 2)), day = s2i(s.substr(6, 2));

	bool ans1 = false, ans2 = false;

	// �������
	for (int i = year; i <= 9999; i++)
	{
		// �����·�
		for (int j = 1; j <= 12; j++)
		{
			if (i == year && j < month)	continue;
			// ��������
			for (int k = 1; k <= 31; k++)
			{
				if (i == year && j == month && k <= day) continue;

				// ��������Ƿ�Ϸ�
				if (!isok(i, j, k)) continue;

				// ������ת��Ϊ�ַ���
				string date = i2s(i, 4) + i2s(j, 2) + i2s(k, 2);

				// ����Ƿ��ǻ�������
				if (!ans1 && isPa(date))
				{
					cout << date << '\n';
					ans1 = true;
				}

				// ����Ƿ��� ABABBABA �͵Ļ�������
				if (!ans2 && isPa2(date))
				{
					cout << date << '\n';
					ans2 = true;
				}
			}
		}
	}
}
