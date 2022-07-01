class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
            for (int i = 0; i < s.length(); i++){
                if (s[i] != ' ')
                    cnt++;
                if (s[i] == ' ' && s[i+1] != ' ' && i != s.length() - 1)
                    cnt = 0;
            }
            return cnt;
    }
};