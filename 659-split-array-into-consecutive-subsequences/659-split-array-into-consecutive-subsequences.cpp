class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> ending, cnt;
        for (int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        for (auto i : nums){
            if (cnt[i] == 0) continue;
            if (ending[i-1] > 0){
                ending[i-1]--;
                ending[i]++;
                cnt[i]--;
            }
            else {
                if (cnt[i+1] == 0 || cnt[i+2] == 0){
                    return 0;
                }
                cnt[i]--;
                cnt[i+1]--;
                cnt[i+2]--;
                ending[i+2]++;
            }
        }
        return 1;
    }
};