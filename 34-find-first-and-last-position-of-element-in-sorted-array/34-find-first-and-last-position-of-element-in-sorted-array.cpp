class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if ((int)nums.size() == 0){
            return {-1, -1};
        }
        int l = 0, r = (int)nums.size() - 1;
        int idx1 = -1, idx2 = -1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                r = mid - 1;
                idx1 = mid;
            }
            else if (nums[mid] > target){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        l = 0; r = (int)nums.size() - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                l = mid + 1;
                idx2 = mid;
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        vector<int> ans = {idx1, idx2};
        return ans;
    }
};