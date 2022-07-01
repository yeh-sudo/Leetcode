class Solution {
public:
    const vector<string> split(const string &str, const char &delimiter){
        vector<string> res;
        stringstream ss(str);
        string tok;
        while (getline(ss, tok, delimiter)){
            res.push_back(tok);
        }
        return res;
    }
    
    bool wordPattern(string pattern, string s) {
        map<char, string> match1;
        map<string, char> match2;
        vector<string> strs = split(s, ' ');
        if ((int)strs.size() != pattern.length()){
            return false;
        }
        for (int i = 0; i < strs.size(); i++){
            if (match1.find(pattern[i]) == match1.end() && match2.find(strs[i]) == match2.end()){
                match1.insert(make_pair(pattern[i], strs[i]));
                match2.insert(make_pair(strs[i], pattern[i]));
            }
            else {
                if (match1[pattern[i]] != strs[i] || match2[strs[i]] != pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
};