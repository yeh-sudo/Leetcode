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
bool cmp(pair<int, int>& a, pair<int, int>& b){
    return (a.second < b.second || (a.second == b.second && a.first <= b.first));
}
class Solution {
    vector<vector<pair<int, int>>> tmp;
    int mn = INT_MAX, mx = INT_MIN;
    void dfs1(TreeNode* node, int r, int c){
        if (!node) return;
        mn = min(c, mn);
        mx = max(c, mx);
        dfs1(node->left, r + 1, c - 1);
        dfs1(node->right, r + 1, c + 1);
    }
    void dfs2(TreeNode* node, int r, int c){
        if (!node) return;
        tmp[c-mn].push_back({node->val, r});
        dfs2(node->left, r + 1, c - 1);
        dfs2(node->right, r + 1, c + 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs1(root, 0, 0);
        tmp.resize(mx - mn + 1);
        dfs2(root, 0, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < tmp.size(); i++){
            sort(tmp[i].begin(), tmp[i].end(), cmp);
            vector<int> a;
            for (int j = 0; j < tmp[i].size(); j++){
                a.push_back(tmp[i][j].first);
            }
            ans.push_back(a);
        }
        return ans;
    }
};