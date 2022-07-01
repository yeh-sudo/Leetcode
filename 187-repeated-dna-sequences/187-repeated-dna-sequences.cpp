class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string, int> lookup;
        int n = s.length();
        for (int i = 0; i <= n - 10; i++){
            string sub = s.substr(i, 10);
            if (lookup.find(sub) == lookup.end()){
                lookup[sub] = 1;
            }
            else {
                lookup[sub]++;
            }
        }
        for (auto &p : lookup){
            if (p.second >= 2){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};