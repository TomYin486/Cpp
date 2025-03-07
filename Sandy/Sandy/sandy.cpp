#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Solution {
public:
	bool evaluateTree(TreeNode* root) {
		// �����ǰ�ڵ���Ҷ�ӽڵ㣨û�����ӣ���ֱ�ӷ�����ֵ��Ӧ�Ĳ���ֵ
		if (root->left == nullptr) return root->val == 0 ? false : true;

		// ������������ֵ
		bool left = evaluateTree(root->left);

		// ������������ֵ
		bool right = evaluateTree(root->right);

		// ���ݵ�ǰ�ڵ��ֵ�������� | ���� & ����
		return root->val == 2 ? left | right : left & right;
	}
};
