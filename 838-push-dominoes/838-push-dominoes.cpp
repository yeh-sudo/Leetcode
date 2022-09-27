class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> r(n), l(n);
        int f = 0;
        for (int i = 0; i < n; i++){
            if (dominoes[i] == 'R'){
                f = n;
                r[i] = f;
                f--;
            }
            else if (dominoes[i] == '.'){
                r[i] = f;
                f = (f - 1 <= 0 ? 0 : f-1);
            }
            else {
                r[i] = 0;
                f = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--){
            if (dominoes[i] == 'L'){
                f = n;
                l[i] = f;
                f--;
            }
            else if (dominoes[i] == '.'){
                l[i] = f;
                f = (f - 1 <= 0 ? 0 : f-1);
            }
            else {
                l[i] = 0;
                f = 0;
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++){
            if (r[i] - l[i] > 0){
                ans += 'R';
            }
            else if (r[i] - l[i] < 0){
                ans += 'L';
            }
            else {
                ans += '.';
            }
        }
        return ans;
    }
};