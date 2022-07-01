class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int col = 0, row = 0;
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int target = n * m;
        while (cnt <= target){
            // right
            for (int i = col; i < m - col; i++){
                ans.push_back(matrix[row][i]);
                cnt++;
            }
            if (cnt >= target){
                break;
            }
            // down
            for (int i = row + 1; i < n - row; i++){
                ans.push_back(matrix[i][m - col - 1]);
                cnt++;
            }
            if (cnt >= target){
                break;
            }
            // left
            for (int i = m - col - 2; i >= col; i--){
                ans.push_back(matrix[n - row - 1][i]);
                cnt++;
            }
            if (cnt >= target){
                break;
            }
            // up
            for (int i = n - row - 2; i > row; i--){
                ans.push_back(matrix[i][col]);
                cnt++;
            }
            if (cnt >= target){
                break;
            }
            col++;
            row++;
        }
        return ans;
    }
};