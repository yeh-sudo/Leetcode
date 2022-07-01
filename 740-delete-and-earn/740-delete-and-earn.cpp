class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> n(10005);
        vector<int> dp(10005);
        for (int i = 0; i < nums.size(); i++){
            n[nums[i]-1]++;
        }
        dp[0] = n[0];
        dp[1] = max(dp[0], n[1] * 2);
        for (int i = 2; i < n.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + n[i] * (i + 1));
        }
        return dp[n.size() - 1];
    }
};