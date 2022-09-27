class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> R, L;
        vector<char> tmp(dominoes.size(), 'x');
        for (int i = 0; i < dominoes.size(); i++){
            if (dominoes[i] == 'R'){
                R.push_back(i);
            }
            else if (dominoes[i] == 'L'){
                L.push_back(i);
            }
        }
        for (int i = 0; i < R.size(); i++){
            int idx = upper_bound(L.begin(), L.end(), R[i]) - L.begin();
            if (idx == L.size()) continue;
            if (i != R.size() - 1 && R[i+1] < L[idx]) continue;
            int num = L[idx] - R[i] + 1;
            int mid = (R[i] + L[idx]) / 2;
            if (num % 2 != 0)
                tmp[mid] = '.';
            else
                tmp[mid] = 'r';
        }
        bool c = 0;
        for (int i = 0; i < dominoes.size(); i++){
            if (c){
                if (tmp[i] == '.'){
                    c = 0;
                }
                else if (tmp[i] == 'r'){
                    c = 0;
                    tmp[i] = 'R';
                }
                else if (dominoes[i] == 'L'){
                    c = 0;
                }
                else {
                    tmp[i] = 'R';
                }
            }
            else {
                if (dominoes[i] == 'R'){
                    c = 1;
                    tmp[i] = 'R';
                }
            }
        }
        c = 0;
        for (int i = dominoes.size() - 1; i >= 0; i--){
            if (c){
                if (tmp[i] == 'R' || tmp[i] == '.'){
                    c = 0;
                }
                else {
                    tmp[i] = 'L';
                }
            }
            else {
                if (dominoes[i] == 'L'){
                    c = 1;
                    tmp[i] = 'L';
                }
            }
        }
        string ans = "";
        for (int i = 0; i < tmp.size(); i++){
            if (tmp[i] == 'x') ans += '.';
            else ans += tmp[i];
        }
        return ans;
    }
};