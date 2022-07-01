class Solution {
public:
    
    bool isvi[201];
    
    int ans = 0;
    
    void dfs(vector<vector<int>>& isConnected, int cur){
        if (isvi[cur]){
            return;
        }
        isvi[cur] = true;
        for (int i = 0; i < isConnected[cur].size(); i++){
            if (!isvi[i] && i != cur && isConnected[cur][i] == 1){
                dfs(isConnected, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        ans = 0;
        memset(isvi, false, sizeof(isvi));
        
        for (int i = 0; i < isConnected.size(); i++){
            if (!isvi[i]){
                dfs(isConnected, i);
                ans++;
            }
        }
        return ans;
    }
};