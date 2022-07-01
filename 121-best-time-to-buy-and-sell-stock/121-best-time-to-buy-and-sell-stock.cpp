class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lmin = prices[0];
        int dp = 0;
        for (int i = 1; i < n; i++){
            dp = max(dp, prices[i] - lmin);
            lmin = min(lmin, prices[i]);
        }
        return dp;
    }
};