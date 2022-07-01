class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while (sum >= target){
                ans = min(ans, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (ans == (int)1e9){
            ans = 0;
        }
        return ans;
    }
};