class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        int ans = 0;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if ((long long)mid * (long long)mid <= x){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};