class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length(), m = s.length();
        int idx = 0;
        for (int i = 0; i < n; i++){
            if (t[i] == s[idx]){
                idx++;
            }
        }
        return (idx - m + 1 > 0) ? 1 : 0;
    }
};