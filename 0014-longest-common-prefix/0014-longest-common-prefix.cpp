class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT_MAX, strIdx;
        for (int i = 0; i < strs.size(); i++){
            int t = strs[i].size();
            if (t <= len){
                len = min(len, t);
                strIdx = i;
            }
        }
        int l = 0, r = len - 1;
        int pos = -1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            bool check = 1;
            for (int i = 0; i < strs.size(); i++){
                for (int j = 0; j <= mid; j++){
                    if (strs[i][j] != strs[strIdx][j]){
                        check = 0;
                        break;
                    }
                }
                if (!check){
                    break;
                }
            }
            if (check){
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        return strs[strIdx].substr(0, pos + 1);
    }
};