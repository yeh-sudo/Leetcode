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
const int mxN = 1e4;
class Solution {
    vector<double> level[mxN + 1];
    int maxL = -1;
    void dfs(TreeNode* node, int L){
        if (!node) return;
        maxL = max(maxL, L);
        level[L].push_back((double)node->val);
        dfs(node->left, L + 1);
        dfs(node->right, L + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        dfs(root, 0);
        for (int i = 0; i <= maxL; i++){
            double sum = 0.0;
            for (int j = 0; j < level[i].size(); j++){
                sum += level[i][j];
            }
            ans.push_back(sum / (double)level[i].size());
        }
        return ans;
    }
};