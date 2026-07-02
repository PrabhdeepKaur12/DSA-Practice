class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, bool goLeft, int length) {
        if (node == NULL) {
            return;
        }

        ans = max(ans, length);

        if (goLeft) {
            dfs(node->left, false, length + 1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->right, true, length + 1);
            dfs(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, false, 1);
        dfs(root->right, true, 1);

        return ans;
    }
};