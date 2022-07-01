class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<char, int> last;
        for (int i = 0; i < s.length(); i++){
            if (last.find(s[i]) == last.end()){
                last[s[i]] = i;
            }
            else {
                last[s[i]] = max(last[s[i]], i);
            }
        }
        int end = 0;
        int cnt = 1;
        for (int i = 0; i < s.length(); i++){
            end = max(last[s[i]], end);
            if (end == i){
                ans.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        return ans;
    }
};