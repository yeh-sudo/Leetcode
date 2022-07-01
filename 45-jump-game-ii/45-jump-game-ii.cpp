class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1){
            return 0;
        }
        int jumps = 0;
        int pos = 0;
        int far = 0;
        while (true){
            jumps++;
            int r = 0;
            for (int i = pos; i <= far; i++){
                r = max(r, i + nums[i]);
            }
            pos = far + 1;
            far = r;
            if (far >= nums.size() - 1){
                return jumps;
            }
        }
        return jumps;
    }
};