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
    
    void dfs(TreeNode* node, int m){
        if (node->val >= m){
            m = max(node->val, m);
            ans++;
        }
        if (node->left != NULL){
            dfs(node->left, m);
        }
        if (node->right != NULL){
            dfs(node->right, m);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return ans;
    }
};