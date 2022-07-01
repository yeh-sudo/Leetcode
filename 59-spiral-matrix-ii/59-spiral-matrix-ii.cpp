class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n);
        vector<vector<int>> ans(n, tmp);
        int target = n * n;
        int cnt = 1;
        int col = 0;
        while (cnt <= target){
            // right
            for (int i = col; i < n - col; i++){
                ans[col][i] = cnt++;
            }
            // down
            for (int i = col + 1; i < n - col; i++){
                ans[i][n - col - 1] = cnt++;
            }
            // left
            for (int i = n - col - 2; i >= col; i--){
                ans[n - col - 1][i] = cnt++;
            }
            // up
            for (int i = n - col - 2; i > col; i--){
                ans[i][col] = cnt++;
            }
            col++;
        }
        return ans;
    }
};