class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        map<int, int> prefix;
        prefix.insert(make_pair(0, 1));
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum - k;
            if (prefix.find(rem) != prefix.end()){
                ans += prefix[rem];
            }
            if (prefix.find(sum) == prefix.end()){
                prefix.insert(make_pair(sum, 1));
            }
            else {
                prefix[sum]++;
            }
        }
        return ans;
    }
};