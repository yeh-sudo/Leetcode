class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        int p = 0;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[0]){
                p = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (p != 0 && target <= nums[p-1] && target >= nums[0]){
            l = 0; r = p - 1;
        }
        else if (target <= nums[nums.size()-1] && target >= nums[p]){
            l = p; r = nums.size() - 1;
        }
        else {
            return -1;
        }
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};