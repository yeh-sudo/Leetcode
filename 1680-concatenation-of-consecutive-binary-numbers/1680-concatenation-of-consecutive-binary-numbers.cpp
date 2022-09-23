#define ll long long
const int mod = 1e9 + 7;
class Solution {
    string generateBinary(ll x, int shift){
        string res = "";
        for (int i = shift; i >= 0; i--){
            if ((ll)(x & (1LL << i)) != 0){
                res += '1';
            }
            else {
                res += '0';
            }
        }
        return res;
    }
public:
    int concatenatedBinary(int n) {
        string ans = "";
        int shift = 0;
        for (int i = 1; i <= n; i++){
            ans += generateBinary(i, shift);
            int cnt = __builtin_popcount(i+1);
            if (cnt == 1) shift++;
        }
        int p = 1;
        int ret = 0;
        for (int i = ans.size() - 1; i >= 0; i--){
            if (ans[i] == '1'){
                ret = ((ret % mod) + (p % mod)) % mod;
            }
            p = ((p % mod) * 2) % mod;
        }
        return ret;
    }
};