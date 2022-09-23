#define ll long long
const int mod = 1e9 + 7;
class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans = 0, next = 1;
        for (int i = 0; i <= n; i++){
            if (i == next){
                next *= 2;
            }
            ans = ((ans % mod) * (next % mod) + i) % mod;
        }
        return ans;
    }
};