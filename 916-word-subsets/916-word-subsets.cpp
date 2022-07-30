class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<vector<int>> cnt;
        vector<int> v(26, 0);
        int n = words1.size(), m = words2.size();
        for (int i = 0; i < n; i++){
            vector<int> tmp(26, 0);
            for (int j = 0; j < words1[i].size(); j++){
                tmp[words1[i][j] - 'a']++;
            }
            cnt.push_back(tmp);
        }
        for (int i = 0; i < m; i++){
            vector<int> tmp(26, 0);
            for (int j = 0; j < words2[i].size(); j++){
                tmp[words2[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; j++){
                v[j] = max(v[j], tmp[j]);
            }
        }
        for (int i = 0; i < n; i++){
            bool valid = 1;
            for (int j = 0; j < 26; j++){
                if (cnt[i][j] < v[j]){
                    valid = 0;
                    break;
                }
            }
            if (valid){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};