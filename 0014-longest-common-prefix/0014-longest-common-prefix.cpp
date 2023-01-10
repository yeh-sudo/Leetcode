class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool check = true;
        int leng = INT_MAX, pos;
        for (int i = 0; i < strs.size(); i++){
            int t = strs[i].size();
            if (t <= leng){
                leng = min(leng, t);
                pos = i;
            }
        }

        for (int i = 0; i < leng; i++){
            for (int j = 1; j < strs.size(); j++){
                if (strs[j][i] != strs[j-1][i]){
                    check = false;
                    break;
                }
            }
            if (check)
                ans += strs[pos][i];
            else
                break;
        }
        return ans;
    }
};