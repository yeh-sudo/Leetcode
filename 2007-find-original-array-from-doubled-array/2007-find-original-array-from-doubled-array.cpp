const int mxN = 1e5;
class Solution {
    int cnt[mxN + 1];
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        memset(cnt, 0, sizeof(cnt));
        vector<int> ans;
        int mx = -1;
        for (int i = 0; i < changed.size(); i++){
            cnt[changed[i]]++;
            mx = max(changed[i], mx);
        }
        for (int i = 0; i < changed.size(); i++){
            if (cnt[changed[i]] != 0){
                if (changed[i] * 2 <= mxN && cnt[changed[i] * 2] != 0){
                    ans.push_back(changed[i]);
                    cnt[changed[i]]--;
                    cnt[changed[i] * 2]--;
                }
            }
        }
        bool valid = 1;
        for (int i = 0; i <= mx; i++){
            valid &= cnt[i] == 0;
        }
        if (valid){
            return ans;
        }
        else {
            return {};
        }
    }
};