class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return 0;
        double k = log10(n) / log10(3);
        int tmp = k;
        if (k == tmp){
            return 1;
        }
        else {
            return 0;
        }
    }
};