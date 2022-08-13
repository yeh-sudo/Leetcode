class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int len = words.size() * words[0].size();
        int wlen = words[0].size();
        unordered_map<string, int> h;
        for (int i = 0; i < words.size(); i++){
            h[words[i]]++;
        }
        if (s.size() < len){
            return ans;
        }
        for (int i = 0; i <= s.size() - len; i++){
            string str = s.substr(i, len);
            unordered_map<string, int> tmp = h;
            for (int k = 0; k < str.size(); k += wlen){
                string ss = str.substr(k, wlen);
                if (tmp.find(ss) != tmp.end()){
                    tmp[ss]--;
                }
            }
            bool valid = 1;
            for (auto p : tmp){
                if (p.second != 0){
                    valid = 0;
                    break;
                }
            }
            if (valid){
                ans.push_back(i);
            }
        }
        return ans;
    }
};