#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param root TreeNode类
     * @return int整型
     */
    int ret = -1010;
    int maxPathSum(TreeNode* root) {
        dfs(root);    // 从根节点开始
        return ret;
    }

    // 返回以当前节点为起点的最大单边路径和，并更新全局最大路径和
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = max(dfs(root->left), 0);   // 统计左子树的最大单链和
        int r = max(dfs(root->right), 0);  // 统计右子树的最大单链和
        // 经过root的最大路径和
        ret = max(ret, root->val + l + r);
        return root->val + max(l, r);  // 当前节点的单边最大值（只能选择左或右子树的一条路径）
    }
};