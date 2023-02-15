class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int>& v, vector<bool>& used, vector<int>& nums){
        if (v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (!used[i]){
                v.push_back(nums[i]);
                used[i] = 1;
                dfs(v, used, nums);
                v.pop_back();
                used[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), 0);
        vector<int> v;
        dfs(v, used, nums);
        return ans;
    }
};