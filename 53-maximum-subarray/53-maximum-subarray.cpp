class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
                return nums[0];
            vector<int> dp(nums.size(), INT_MIN);
            vector<int> sum;
            for (int i = 0; i < nums.size(); i++){
                if (i == 0){
                    sum.push_back(nums[i]);
                    dp[i] = nums[i];
                    continue;
                }
                sum.push_back(max(sum[i-1] + nums[i], nums[i]));
                if (sum[i] > dp[i-1])
                    dp[i] = sum[i];
                else
                    dp[i] = dp[i-1];
            }
            return dp[nums.size()-1];
    }
};