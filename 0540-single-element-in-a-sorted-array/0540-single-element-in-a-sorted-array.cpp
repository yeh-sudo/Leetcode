class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ans = 0;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (mid == 0){
                if (nums.size() == 1 || nums[mid+1] != nums[mid]){
                    ans = nums[mid];
                    break;
                }
            } else if (mid == nums.size() - 1){
                if (nums[mid-1] != nums[mid]){
                    ans = nums[mid];
                    break;
                }
            } else {
                if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                    ans = nums[mid];
                    break;
                } else if (nums[mid] == nums[mid-1]){
                    if ((r - mid) % 2 == 0){
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    if ((r - mid + 1) % 2 == 0){
                        r = mid - 1;
                    } else {
                        l = mid;
                    }
                }
            }
        }
        return ans;
    }
};