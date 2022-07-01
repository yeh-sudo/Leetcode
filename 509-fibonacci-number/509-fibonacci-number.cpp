class Solution {
public:
    int fib(int n) {
        int ans = 0;
        int cur1 = 0;
        int cur2 = 1;
        if (n == 0){
            return cur1;
        }
        else if (n == 1){
            return cur2;
        }
        for (int i = 2; i <= n; i++){
            ans = cur1 + cur2;
            cur1 = cur2;
            cur2 = ans;
        }
        return ans;
    }
};