class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        unordered_set<char> checkSet;
        for (int i = 0; i < board.size(); i++){
            checkSet.clear();
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != '.'){
                    if (checkSet.count(board[i][j])){
                        valid = false;
                    } else {
                        checkSet.insert(board[i][j]);
                    }
                }
            }
        }
        for (int j = 0; j < board[0].size(); j++){
            checkSet.clear();
            for (int i = 0; i < board.size(); i++){
                if (board[i][j] != '.'){
                    if (checkSet.count(board[i][j])){
                        valid = false;
                    } else {
                        checkSet.insert(board[i][j]);
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i += 3){
            for (int j = 0; j < board[i].size(); j += 3){
                checkSet.clear();
                for (int r = i; r < i + 3; r++){
                    for (int c = j; c < j + 3; c++){
                        if (board[r][c] != '.'){
                            if (checkSet.count(board[r][c])){
                                valid = false;
                            } else {
                                checkSet.insert(board[r][c]);
                            }
                        }
                    }
                }
            }
        }
        return valid;
    }
};