class Solution {
    int dp[1001][1001];
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (nums1[i] == nums2[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                    ans = max(ans, dp[i+1][j+1]);
                }
            }
        }
        return ans;
    }
};