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
    void dfs(TreeNode* cur, int d, int val, int target){
        if (!cur) return;
        if (d == target - 1){
            TreeNode* newLeft = new TreeNode(val, cur->left, NULL);
            cur->left = newLeft;
            TreeNode* newRight = new TreeNode(val, NULL, cur->right);
            cur->right = newRight;
            return;
        }
        dfs(cur->left, d + 1, val, target);
        dfs(cur->right, d + 1, val, target);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* newRoot = new TreeNode(val, root, NULL);
            return newRoot;
        }
        dfs(root, 1, val, depth);
        return root;
    }
};