class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        for (int i = 1; i < prefix.size(); i++){
            m[(prefix[i] % k + k) % k]++;
            cout << prefix[i] << ' ';
        }
        int ans = 0;
        for (auto p : m){
            if (p.first == 0){
                ans += p.second;
                ans += (p.second * (p.second - 1)) / 2;
            } else {
                ans += (p.second * (p.second - 1)) / 2;
            }
        }
        return ans;
    }
};