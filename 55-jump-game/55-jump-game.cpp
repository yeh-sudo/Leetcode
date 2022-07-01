class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = false;
        if (nums.size() == 1){
            return true;
        }
        int m = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (i <= m){
                m = max(m, i + nums[i]);
                if (i == nums.size() - 1){
                    ans = true;
                }
            }
            else {
                break;
            }
        }
        return ans;
    }
};