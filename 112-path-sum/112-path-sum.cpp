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
    bool find = 0;
    void dfs(TreeNode* node, int sum, int target){
        if (!node) return;
        if (!node->left && !node->right){
            if (sum + node->val == target) find = 1;
            return;
        }
        sum += node->val;
        dfs(node->left, sum, target);
        dfs(node->right, sum, target);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return find;
    }
};