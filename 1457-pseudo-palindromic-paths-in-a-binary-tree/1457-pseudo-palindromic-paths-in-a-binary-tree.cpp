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
    bool valid(vector<int>& v){
        int odd = 0;
        for (int i = 1; i < 10; i++){
            if (v[i] % 2 == 1) odd++;
        }
        if (odd > 1){
            return 0;
        }
        return 1;
    }
    void dfs(vector<int>& v, TreeNode* node){
        if (!node->left && !node->right){
            if (valid(v)) ans++;
            return;
        }
        if (node->left){
            v[node->left->val]++;
            dfs(v, node->left);
            v[node->left->val]--;
        }
        if (node->right){
            v[node->right->val]++;
            dfs(v, node->right);
            v[node->right->val]--;
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10);
        v[root->val]++;
        dfs(v, root);
        return ans;
    }
};