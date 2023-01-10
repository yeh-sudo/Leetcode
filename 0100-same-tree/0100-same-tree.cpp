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
    bool dfs(TreeNode *p, TreeNode *q){
        if (p == NULL && q != NULL){
            return 0;
        }
        if (q == NULL && p != NULL){
            return 0;
        }
        if (p == NULL && q == NULL){
            return 1;
        }
        if (p->val != q->val){
            return 0;
        }
        bool left = dfs(p->left, q->left);
        bool right = dfs(p->right, q->right);
        return left & right;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};