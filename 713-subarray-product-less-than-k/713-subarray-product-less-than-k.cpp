class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0, r = 0;
        int m = 1;
        while (r < nums.size() && l < nums.size()){
            m *= nums[r];
            while (m >= k && l < nums.size()){
                m /= nums[l];
                l++;
            }
            if (l >= nums.size()){
                break;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
};