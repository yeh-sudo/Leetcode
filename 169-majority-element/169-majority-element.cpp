class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int canditate = nums[0], cnt = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != canditate){
                cnt--;
                if (cnt == 0){
                    canditate = nums[i];
                    cnt++;
                }
            }
            else {
                cnt++;
            }
        }
        return canditate;
    }
};