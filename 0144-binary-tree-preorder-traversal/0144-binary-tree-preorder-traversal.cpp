class Solution {
public:
    TreeNode* rightMostFinder(TreeNode *cur, TreeNode *root){
        while (cur->right && cur->right != root){
            cur=cur->right;
        }
        return cur;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode*cur = root;
        vector<int> ans;
        while (cur){
            TreeNode *leftNode = cur->left;
            if (leftNode){
                TreeNode *RightMost = rightMostFinder(leftNode, cur);
                if (RightMost->right){
                    RightMost->right = nullptr;
                    cur=cur->right;
                }
                else {
                    RightMost->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }
            }
            else {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};