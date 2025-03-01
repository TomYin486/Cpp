#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // ��������ջ�������ų�ջ
        stack<char> stk;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else {
                if (stk.empty()) {
                    return false;  // û��ƥ���������
                }
                char top = stk.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    stk.pop();
                }
                else return false;  // ���Ų�ƥ��
            }
        }
        return stk.empty();  // ���ջΪ�գ�˵���������Ŷ�ƥ��
    }
};
