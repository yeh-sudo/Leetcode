class Solution {
public:
    // two pointers solution
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int L = i + 1;
            int R = n - 1;
            while (L < R){
                if (nums[L] + nums[R] == target){
                    vector<int> tmp = {nums[i], nums[L], nums[R]};
                    ans.push_back(tmp);
                    L++;
                    while (L < R && nums[L] == nums[L-1]){
                        L++;
                    }
                }
                else if (nums[L] + nums[R] > target){
                    R--;
                }
                else {
                    L++;
                }
            }
        }
        return ans;
    }
};