const int mod = 1e9 + 7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long>(target+1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= k; j++){
                for (int a = j; a <= target; a++){
                    dp[i][a] += dp[i-1][a-j] % mod;
                }
            }
        }
        return dp[n][target] % mod;
    }
};