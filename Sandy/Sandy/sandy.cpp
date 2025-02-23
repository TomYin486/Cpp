#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 将字符串转换为整数
int s2i(string s)
{
	int res = 0;
	for (const auto& i : s)
	{
		res = res * 10 + i - '0';
	}
	return res;
}

// 将整数转换为字符串，并确保字符串的长度为 w
string i2s(int x, int w)
{
	string res;
	while (x) res += (x % 10) + '0', x /= 10;
	while (res.length() < w) res += '0';
	reverse(res.begin(), res.end());
	return res;
}

// 判断是否是闰年
bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 判断日期是否合法
bool isok(int year, int month, int day)
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year))
	{
		days[2] = 29;
	}
	return day <= days[month];
}

// 判断字符串是否是回文
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

// 判断字符串是否是 ABABBABA 型的回文
bool isPa2(string s)
{
	if (!isPa(s))
	{
		return false;
	}
	return s[0] == s[2] && s[1] == s[3];
}

// s2i 函数：将字符串转换为整数
// i2s 函数：将整数转换为字符串，并确保字符串的长度为指定长度
// isLeapYear 函数：判断某年是否是闰年
// isok 函数：判断给定的年、月、日是否是一个合法的日期
// isPa 函数：判断一个字符串是否是回文
// isPa2 函数：判断一个字符串是否是 ABABBABA 型的回文

int main()
{
	string s; cin >> s;
	int year = s2i(s.substr(0, 4)), month = s2i(s.substr(4, 2)), day = s2i(s.substr(6, 2));

	bool ans1 = false, ans2 = false;

	// 遍历年份
	for (int i = year; i <= 9999; i++)
	{
		// 遍历月份
		for (int j = 1; j <= 12; j++)
		{
			if (i == year && j < month)	continue;
			// 遍历天数
			for (int k = 1; k <= 31; k++)
			{
				if (i == year && j == month && k <= day) continue;

				// 检查日期是否合法
				if (!isok(i, j, k)) continue;

				// 将日期转换为字符串
				string date = i2s(i, 4) + i2s(j, 2) + i2s(k, 2);

				// 检查是否是回文日期
				if (!ans1 && isPa(date))
				{
					cout << date << '\n';
					ans1 = true;
				}

				// 检查是否是 ABABBABA 型的回文日期
				if (!ans2 && isPa2(date))
				{
					cout << date << '\n';
					ans2 = true;
				}
			}
		}
	}
}
