class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]){
            return 0;
        }
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (obstacleGrid[i-1][j-1]){
                    continue;
                }
                int top = 0, left = 0;
                if (i != 1 && !obstacleGrid[i-2][j-1])
                    top = dp[i-1][j];
                if (j != 1 && !obstacleGrid[i-1][j-2])
                    left = dp[i][j-1];
                dp[i][j] += top + left;
            }
        }
        return dp[n][m];
    }
};