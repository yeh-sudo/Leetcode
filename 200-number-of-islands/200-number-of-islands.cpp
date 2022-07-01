class Solution {
public:
    const int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    bool isvi[305][305];
    
    int ans;
    
    void dfs(int x, int y, vector<vector<char>>& grid){
        if (isvi[x][y]){
            return;
        }
        isvi[x][y] = true;
        for (int i = 0; i < 4; i++){
            int nextx = x + dir[i][0], nexty = y + dir[i][1];
            if (nextx < 0 || nextx > grid.size() - 1 || nexty < 0 || nexty > grid[0].size() - 1){
                continue;
            }
            if (!isvi[nextx][nexty] && grid[nextx][nexty] == '1'){
                dfs(nextx, nexty, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        memset(isvi, false, sizeof(isvi));
        
        ans = 0;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (!isvi[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};