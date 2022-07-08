class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
                if (s[i-1] == s1[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        return dp[n][n];
    }
};