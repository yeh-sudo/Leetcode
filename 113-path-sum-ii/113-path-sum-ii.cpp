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
    vector<vector<int>> ans;
    void dfs(vector<int> v, TreeNode* node, int targetSum, int sum){
        if (!node->left && !node->right){
            if (sum + node->val == targetSum){
                v.push_back(node->val);
                ans.push_back(v);
                return;
            }
        }
        // cout << node->val << '\n';
        if (node->left){
            v.push_back(node->val);
            sum += node->val;
            dfs(v, node->left, targetSum, sum);
            v.pop_back();
            sum -= node->val;
        }
        if (node->right){
            v.push_back(node->val);
            sum += node->val;
            dfs(v, node->right, targetSum, sum);
            v.pop_back();
            sum -= node->val;
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<int> v;
        dfs(v, root, targetSum, 0);
        return ans;
    }
};