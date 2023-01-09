class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++){
            int r = 0, c = i;
            while (1){
                if (r == n){
                    ans[i] = c;
                    break;
                }
                if (grid[r][c] == 1){
                    // look right
                    if (c + 1 == m || grid[r][c+1] == -1){
                        break;
                    }
                    r++; c++;
                } else {
                    // look left
                    if (c - 1 < 0 || grid[r][c-1] == 1){
                        break;
                    }
                    r++; c--;
                }
            }
        }
        return ans;
    }
};