class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int l = 0, r = p.length() - 1;
        if (s.length() < p.length()){
            return ans;
        }
        map<char, int> pm;
        map<char, int> am;
        for (int i = 0; i < 26; i++){
            am.insert(make_pair('a' + i, 0));
        }
        for (int i = 0; i < p.length(); i++){
            if (pm.find(p[i]) == pm.end()){
                pm.insert(make_pair(p[i], 1));
            }
            else {
                pm[p[i]]++;
            }
            am[s[i]]++;
        }
        for (int i = p.length() - 1; i < s.length(); i++){
            bool valid = true;
            for (auto p : pm){
                if (am[p.first] == p.second){
                    continue;
                }
                else {
                    valid = false;
                    break;
                }
            }
            if (valid){
                ans.push_back(l);
            }
            am[s[l]]--;
            l++;
            if (i + 1 != s.length()){
                am[s[i+1]]++;
            }
        }
        return ans;
    }
};