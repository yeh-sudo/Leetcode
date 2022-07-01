class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alph(52, 0);
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++){
            int idx;
            if (isupper(s[i])){
                idx = s[i] - 'A';
            }
            else {
                idx = s[i] - 'a' + 26;
            }
            alph[idx]++;
            if (alph[idx] == 2){
                ans += 2;
                alph[idx] -= 2;
            }
        }
        for (int i = 0; i < alph.size(); i++){
            if (alph[i] == 1){
                ans++;
                break;
            }
        }
        return ans;
    }
};