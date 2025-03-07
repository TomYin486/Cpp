#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Solution {
public:
	bool evaluateTree(TreeNode* root) {
		// 如果当前节点是叶子节点（没有左孩子），直接返回其值对应的布尔值
		if (root->left == nullptr) return root->val == 0 ? false : true;

		// 计算左子树的值
		bool left = evaluateTree(root->left);

		// 计算右子树的值
		bool right = evaluateTree(root->right);

		// 根据当前节点的值决定进行 | 还是 & 操作
		return root->val == 2 ? left | right : left & right;
	}
};
