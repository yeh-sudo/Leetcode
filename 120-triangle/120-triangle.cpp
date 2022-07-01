class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n-1].size();
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i + 1; j++){
                if (j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if (j == i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++){
            ans = min(dp[n-1][i], ans);
        }
        return ans;
    }
};