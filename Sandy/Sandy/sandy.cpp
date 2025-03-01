#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 左括号入栈，右括号出栈
        stack<char> stk;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else {
                if (stk.empty()) {
                    return false;  // 没有匹配的左括号
                }
                char top = stk.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    stk.pop();
                }
                else return false;  // 括号不匹配
            }
        }
        return stk.empty();  // 如果栈为空，说明所有括号都匹配
    }
};
