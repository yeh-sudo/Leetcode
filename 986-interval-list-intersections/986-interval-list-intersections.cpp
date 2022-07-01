class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int s1 = 0, s2 = 0;
        while (s1 != f.size() && s2 != s.size()){
            int l = max(f[s1][0], s[s2][0]);
            int lb = min(f[s1][0], s[s2][0]);
            int r = min(f[s1][1], s[s2][1]);
            int rb = max(f[s1][1], s[s2][1]);
            if (r < l){
                if (r == f[s1][1]){
                    s1++;
                }
                else if (r == s[s2][1]){
                    s2++;
                }
            }
            else {
                vector<int> tmp = {l, r};
                ans.push_back(tmp);
                if (r == f[s1][1]){
                    s1++;
                }
                else if (r == s[s2][1]){
                    s2++;
                }
            }
        }
        return ans;
    }
};