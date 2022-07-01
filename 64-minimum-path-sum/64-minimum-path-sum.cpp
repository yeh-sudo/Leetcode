#define init 0x3f3f3f3f

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n+1][m+1];
        memset(dp, init, sizeof(dp));
        dp[1][1] = grid[0][0];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (i == 1 && j == 1)
                    continue;
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};