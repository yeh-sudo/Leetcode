class Solution {
public:
    int findMin(vector<int>& nums) {
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
        return nums[p];
    }
};