class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> backward(nums.size());
        vector<int> forward(nums.size());
        backward[backward.size()-1] = nums[nums.size()-1];
        forward[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            forward[i] = min(forward[i-1], nums[i]);
        }
        for (int i = nums.size()-2; i >= 0; i--){
            backward[i] = max(backward[i+1], nums[i]);
        }
        for (int i = 0; i < nums.size(); i++){
            if (forward[i] < nums[i] && nums[i] < backward[i]){
                return true;
            }
        }
        return false;
    }
};