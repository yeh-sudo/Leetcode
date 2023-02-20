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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL){
            return ans;
        }
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()){
            pair<int, TreeNode*> cur = q.front();
            q.pop();
            if (cur.first >= ans.size()){
                vector<int> tmp;
                ans.push_back(tmp);
            }
            ans[cur.first].push_back(cur.second->val);
            if (cur.second->left != NULL){
                q.push({cur.first + 1, cur.second->left});
            }
            if (cur.second->right != NULL){
                q.push({cur.first + 1, cur.second->right});
            }
        }
        return ans;
    }
};