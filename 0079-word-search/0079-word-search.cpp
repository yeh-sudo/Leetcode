class Solution {
    bool isvi[7][7];
    const int x[4] = {0, 0, 1, -1};
    const int y[4] = {-1, 1, 0, 0};
    bool dfs(int i, int j, string str, vector<vector<char>>& board, string word){
        // cout << i << ' ' << j << ' ' << str << '\n';
        if (str == word){
            return true;
        } else {
            bool valid = true;
            for (int i = 0; i < str.size(); i++){
                if (str[i] != word[i]){
                    valid = false;
                    break;
                }
            }
            if (!valid){
                return false;
            }
        }
        if (isvi[i][j]){
            return false;
        }
        isvi[i][j] = 1;
        for (int k = 0; k < 4; k++){
            if (i + x[k] >= 0 && i + x[k] < board.size() && j + y[k] >= 0 && j + y[k] < board[i].size() && !isvi[i + x[k]][j + y[k]]){
                if (dfs(i + x[k], j + y[k], str + board[i+x[k]][j+y[k]], board, word)){
                    return true;
                }
            }
        }
        isvi[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != word[0]){
                    continue;
                }
                memset(isvi, 0, sizeof(isvi));
                string str = "";
                str += board[i][j];
                if (dfs(i, j, str, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};