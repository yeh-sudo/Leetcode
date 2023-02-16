/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
    void dfs(TreeNode *cur, int depth){
        if (cur == NULL){
            return;
        }
        ans = max(ans, depth);
        dfs(cur->left, depth + 1);
        dfs(cur->right, depth + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        dfs(root, 1);
        return ans;
    }
};