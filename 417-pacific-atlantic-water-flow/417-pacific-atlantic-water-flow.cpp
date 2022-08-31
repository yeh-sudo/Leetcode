class Solution {
    const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size(), m = heights[0].size();
        bool vi[n+1][m+1];
        bool valid[n+1][m+1];
        memset(valid, 0, sizeof(valid));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                bool p = 0, a = 0;
                memset(vi, 0, sizeof(vi));
                queue<vector<int>> q;
                q.push({i, j});
                while (!q.empty()){
                    vector<int> cur = q.front();
                    q.pop();
                    if (cur[0] == 0 || cur[1] == 0){
                        p = 1;
                    }
                    if (cur[0] == n - 1 || cur[1] == m - 1){
                        a = 1;
                    }
                    if (a && p) {
                        ans.push_back({i, j});
                        valid[i][j] = 1;
                        break;
                    }
                    if (vi[cur[0]][cur[1]]) continue;
                    vi[cur[0]][cur[1]] = 1;
                    for (int k = 0; k < 4; k++){
                        int next_i = cur[0] + d4i[k], next_j = cur[1] + d4j[k];
                        if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && heights[cur[0]][cur[1]] >= heights[next_i][next_j]){
                            if (valid[next_i][next_j]) p = 1, a = 1;
                            q.push({next_i, next_j});
                        }
                    }
                }
            }
        }
        return ans;
    }
};