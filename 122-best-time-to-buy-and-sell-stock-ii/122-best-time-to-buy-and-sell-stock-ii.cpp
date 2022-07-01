class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp = 0;
        prices.push_back(-1);
        int lmin = prices[0];
        for (int i = 1; i < n + 1; i++){
            if (prices[i] < prices[i-1]){
                dp = dp + prices[i-1] - lmin;
                lmin = prices[i];
            }
        }
        return dp;
    }
};