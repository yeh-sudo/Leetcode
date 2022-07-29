class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, char> p;
        unordered_set<char> s;
        int n = words.size();
        for (int i = 0; i < n; i++){
            p.clear();
            s.clear();
            bool valid = 1;
            for (int k = 0; k < pattern.size(); k++){
                if (p.find(pattern[k]) == p.end() && !s.count(words[i][k])){
                    p[pattern[k]] = words[i][k];
                    s.insert(words[i][k]);
                }
                else {
                    if (p[pattern[k]] != words[i][k]){
                        valid = 0;
                        break;
                    }
                }
            }
            if (valid){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};