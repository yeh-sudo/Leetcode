class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if (n + m != k){
            return 0;
        }
        if (n == 0 && m == 0){
            return 1;
        }
        int dp[n+5][m+5];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        s1 = '#' + s1;
        s2 = '#' + s2;
        s3 = '#' + s3;
        for (int i = 1; i <= s1.size(); i++){
            if (s1[i] == s3[i])
                dp[i][0] = 1;
            else
                break;
        }
        for (int i = 1; i <= s2.size(); i++){
            if (s2[i] == s3[i])
                dp[0][i] = 1;
            else
                break;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (s1[i] == s3[i+j] && dp[i-1][j])
                    dp[i][j] = 1;
                if (s2[j] == s3[i+j] && dp[i][j-1])
                    dp[i][j] = 1;
            }
        }
        return dp[n][m];
    }
};