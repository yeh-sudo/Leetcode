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
    TreeNode* convert(vector<int>& nums, int l, int r){
        if (l > r){
            return NULL;
        }
        int mid = (l + r) / 2;
        TreeNode *node = new TreeNode();
        node->val = nums[mid];
        node->left = convert(nums, l, mid-1);
        node->right = convert(nums, mid + 1, r);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return NULL;
        }
        TreeNode *root = convert(nums, 0, n-1);
        return root;
    }
};