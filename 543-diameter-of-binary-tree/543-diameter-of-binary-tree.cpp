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
    
    int dfs(TreeNode* node){
        int mx = 0;
        if (node->left != NULL){
            int len = 1 + dfs(node->left);
            ans = max(ans, mx + len);
            mx = max(mx, len);
        }
        
        if (node->right != NULL){
            int len = 1 + dfs(node->right);
            ans = max(ans, mx + len);
            mx = max(mx, len);
        }
        return mx;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};