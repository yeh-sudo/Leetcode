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
    bool dfs(TreeNode* node){
        if (!node) return 0;
        bool valid = 0;
        if (!dfs(node->left)){
            node->left = NULL;
        }
        else {
            valid = 1;
        }
        if (!dfs(node->right)){
            node->right = NULL;
        }
        else {
            valid = 1;
        }
        if (node->val || valid){
            return 1;
        }
        else {
            return 0;
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool tmp = dfs(root);
        if (!tmp) return NULL;
        if (!root->left && !root->right && !root->val) return NULL;
        return root;
    }
};