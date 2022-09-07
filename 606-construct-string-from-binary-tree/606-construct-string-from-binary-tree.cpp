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
    string ans = "";
    void dfs(TreeNode* node){
        if (!node->left && node->right){
            ans += "()";
        }
        else if (node->left){
            string tmp = to_string(node->left->val);
            ans += "(" + tmp;
            dfs(node->left);
            ans += ")";
        }
        if (node->right){
            string tmp = to_string(node->right->val);
            ans += "(" + tmp;
            dfs(node->right);
            ans += ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string tmp = to_string(root->val);
        ans += tmp;
        dfs(root);
        return ans;
    }
};