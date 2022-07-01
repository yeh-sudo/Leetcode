class Solution {
public:
    std::vector<int> s = std::vector<int>(50);
    
    int climbStairs(int n) {
        if (s[n] != 0){
            return s[n];
        }
        s[0] = 1;
        s[1] = 1;
        for (int i = 2; i <= n; i++){
            s[i] = s[i-1] + s[i-2];
        }
        return s[n];
    }
};