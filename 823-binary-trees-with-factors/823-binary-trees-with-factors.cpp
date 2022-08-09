class Solution {
    const int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            dp[arr[i]] = 1;
        }
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (arr[i] % arr[j] == 0 && dp.find(arr[i] / arr[j]) != dp.end()){
                    int num = arr[i] / arr[j];
                    dp[arr[i]] += (dp[arr[j]] * dp[num]) % mod;
                }
            }
        }
        long long ans = 0;
        for (auto p : dp){
            ans += p.second % mod;
        }
        return ans % mod;
    }
};
