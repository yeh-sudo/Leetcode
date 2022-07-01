class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, en = nums.size()-1, mid;
            while (beg <= en){
                mid = (beg + en) / 2;
                if (nums[mid] == target){
                    return mid;
                }
                if (nums[mid] > target)
                    en = mid - 1;
                else 
                    beg = mid + 1;
            }
            return beg;
    }
};