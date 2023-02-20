class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0, l = 0, r = nums.size()-1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                ans = mid;
                break;
            } else if (nums[mid] < target){
                l = mid + 1;
                ans = l;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};