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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL){
            return ans;
        }
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()){
            pair<int, TreeNode*> node = q.front();
            q.pop();
            if (ans.size() <= node.first){
                vector<int> tmp;
                ans.push_back(tmp);
            }
            if (node.first % 2 == 0){
                ans[node.first].push_back(node.second->val);
            } else {
                ans[node.first].insert(ans[node.first].begin(), node.second->val);
            }
            if (node.second->left != NULL){
                q.push({node.first + 1, node.second->left});
            }
            if (node.second->right != NULL){
                q.push({node.first + 1, node.second->right});
            }
        }
        return ans;
    }
};