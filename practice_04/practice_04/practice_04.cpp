#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param root TreeNode��
     * @return int����
     */
    int ret = -1010;
    int maxPathSum(TreeNode* root) {
        dfs(root);    // �Ӹ��ڵ㿪ʼ
        return ret;
    }

    // �����Ե�ǰ�ڵ�Ϊ������󵥱�·���ͣ�������ȫ�����·����
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = max(dfs(root->left), 0);   // ͳ�����������������
        int r = max(dfs(root->right), 0);  // ͳ�����������������
        // ����root�����·����
        ret = max(ret, root->val + l + r);
        return root->val + max(l, r);  // ��ǰ�ڵ�ĵ������ֵ��ֻ��ѡ�������������һ��·����
    }
};