class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int turn = 0;
        int n = matrix.size() * matrix[0].size();
        int cnt = 0;
        int i = 0, j = 0;
        int left = -1, right = matrix[0].size(), top = -1, bottom = matrix.size();
        while (cnt < n){
            ans.push_back(matrix[i][j]);
            if (turn % 4 == 0){
                // right
                if (j + 1 == right){
                    turn = (++turn) % 4;
                    top++;
                    i++;
                } else {
                    j++;
                }
            } else if (turn % 4 == 1){
                // down
                if (i + 1 == bottom){
                    turn = (++turn) % 4;
                    right--;
                    j--;
                } else {
                    i++;
                }
            } else if (turn % 4 == 2){
                // left
                if (j - 1 == left){
                    turn = (++turn) % 4;
                    bottom--;
                    i--;
                } else {
                    j--;
                }
            } else {
                // up
                if (i - 1 == top){
                    turn = (++turn) % 4;
                    left++;
                    j++;
                } else {
                    i--;
                }
            }
            cnt++;
        }
        return ans;
    }
};