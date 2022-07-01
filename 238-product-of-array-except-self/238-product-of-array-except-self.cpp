class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefix = 1;
        for (int i = n - 2; i >= 0; i--){
            ans[i] = ans[i+1] * nums[i+1];
        }
        for (int i = 1; i < n; i++){
            prefix *= nums[i-1];
            ans[i] *= prefix;
        }
        return ans;
    }
};