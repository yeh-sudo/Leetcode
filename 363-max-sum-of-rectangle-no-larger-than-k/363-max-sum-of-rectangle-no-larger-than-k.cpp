class Solution {
    long long sum[102][102];
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                for (int p1 = i; p1 <= n; p1++){
                    for (int p2 = j; p2 <= m; p2++){
                        int tmp = sum[p1][p2] - sum[p1-i][p2] - sum[p1][p2-j] + sum[p1-i][p2-j];
                        if (tmp <= k && tmp >= ans){
                            ans = tmp;
                        }
                    }
                }
            }
        }
        return ans;
    }
};