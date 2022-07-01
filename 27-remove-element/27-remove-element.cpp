class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> tmp;
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] != val){
                    tmp.push_back(nums[i]);
                }
            }
            nums.clear();
            nums = tmp;
            return nums.size();
    }
};