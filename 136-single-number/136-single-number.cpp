class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++){
            if (cnt.find(nums[i]) == cnt.end()){
                cnt.insert(make_pair(nums[i], 1));
            }
            else {
                cnt[nums[i]]++;
            }
        }
        for (auto& p : cnt){
            if (p.second == 1){
                ans = p.first;
                break;
            }
        }
        return ans;
    }
};