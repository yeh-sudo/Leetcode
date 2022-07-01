class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
            map<int, int> numsMap;
            for (int i = 0; i < nums.size(); i++){
                if (numsMap.find(target - nums[i]) != numsMap.end()){
                    ans.push_back(numsMap[target - nums[i]]);
                    ans.push_back(i);
                    return ans;
                }
                numsMap.insert(pair<int, int>(nums[i], i));
            }
            return {0, 0};
    }
};