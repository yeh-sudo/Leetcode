class Solution {
    int countLen(long long x){
        int len = 0;
        for (int i = 31; i >= 0; i--){
            if ((long long)(x & (1LL << i)) != 0){
                len = max(len, i + 1);
            }
        }
        return len;
    }
public:
    int divide(int dividend, int divisor) {
        int k = -1;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)){
            k = 1;
        }
        long long Dividend = abs((long long)dividend);
        long long Divisor = abs((long long)divisor);
        int dividendLen = countLen(Dividend), divisorLen = countLen(Divisor);
        if (dividendLen < divisorLen){
            return 0;
        }
        long long tmp = (Divisor << (long long)(dividendLen - divisorLen));
        string bits = "";
        for (int i = 0; i < dividendLen - divisorLen + 1; i++){
            if (Dividend >= tmp){
                Dividend -= tmp;
                bits += "1";
            } else {
                bits += "0";
            }
            tmp >>= 1;
        }
        long long ans = 0, p = 1;
        for (int i = bits.size() - 1; i >= 0; i--){
            if (bits[i] == '1'){
                ans += p;
            }
            p *= 2;
        }
        if (ans * k >= INT_MAX){
            return INT_MAX;
        }
        if (ans * k <= INT_MIN){
            return INT_MIN;
        }
        return ans * k;
    }
};