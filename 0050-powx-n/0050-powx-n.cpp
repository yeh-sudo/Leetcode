class Solution {
public:
    double myPow(double x, int n) {
        bool inverse = (n >= 0 ? 0 : 1);
        long long idx = abs((long long)n);
        double ans = 1.0;
        while (idx != 0){
            if (idx & 1){
                ans *= x;
            }
            x *= x;
            idx >>= 1;
        }
        if (inverse){
            ans = 1.0 / ans;
        }
        return ans;
    }
};