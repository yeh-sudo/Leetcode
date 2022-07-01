class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int r = height.size() - 1, l = 0;
        while (l < r){
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[r] >= height[l]){
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};