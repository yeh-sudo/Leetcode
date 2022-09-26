class Solution {
    vector<char> adj[26];
    bool isvi[26];
    bool dfs(char cur, char e){
        if (isvi[cur-'a']) return 1;
        if (cur == e) return 0;
        isvi[cur-'a'] = 1;
        for (int i = 0; i < adj[cur-'a'].size(); i++){
            if (!dfs(adj[cur-'a'][i], e)) return 0;
        }
        return 1;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < equations.size(); i++){
            if (equations[i][1] == '='){
                adj[equations[i][0]-'a'].push_back(equations[i][3]);
                adj[equations[i][3]-'a'].push_back(equations[i][0]);
            }
        }
        for (int i = 0; i < equations.size(); i++){
            if (equations[i][1] == '!'){
                memset(isvi, 0, sizeof(isvi));
                if (!dfs(equations[i][0], equations[i][3])){
                    return 0;
                }
            }
        }
        return 1;
    }
};