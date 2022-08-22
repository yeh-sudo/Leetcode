class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt = 0;
        if (n == 0) return 0;
        while (n != 1){
            if (n % 2 == 0){
                n >>= 1;
                cnt++;
            }
            else {
                if (n != 1){
                    return 0;
                }
            }
        }
        if (cnt % 2 == 0) return 1;
        return 0;
    }
};