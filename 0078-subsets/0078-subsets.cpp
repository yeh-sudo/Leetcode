class Solution {
    vector<vector<int>> ans;
    void subset(vector<int>& v, vector<int>& nums, int idx){
        if (idx >= nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        subset(v, nums, idx + 1);
        v.pop_back();
        subset(v, nums, idx + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        subset(v, nums, 0);
        return ans;
    }
};