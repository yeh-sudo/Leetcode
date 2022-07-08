class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, same = 0, cnt = 0;
        multiset<string> s;
        for (int i = 0; i < words.size(); i++){
            if (words[i][0] == words[i][1]){
                cnt++;
                if (s.find(words[i]) != s.end()){
                    s.erase(s.find(words[i]));
                    same += 2;
                    ans += 4;
                }
                else {
                    s.insert(words[i]);
                }
            }
            else {
                string str = words[i];
                reverse(str.begin(), str.end());
                if (s.find(str) != s.end()){
                    s.erase(s.find(str));
                    ans += 4;
                }
                else {
                    s.insert(words[i]);
                }
            }
        }
        if (cnt - same != 0){
            ans += 2;
        }
        return ans;
    }
};