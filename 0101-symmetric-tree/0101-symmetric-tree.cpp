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
    bool valid(TreeNode* leftNode, TreeNode* rightNode){
        if (leftNode == NULL && rightNode == NULL){
            return true;
        } else if (leftNode != NULL && rightNode != NULL){
            if (leftNode->val == rightNode->val){
                bool left = valid(leftNode->left, rightNode->right);
                bool right = valid(leftNode->right, rightNode->left);
                return left & right;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        return valid(root->left, root->right);
    }
};