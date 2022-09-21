class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0, n = nums.size(), q = queries.size();
        for (int i = 0; i < n; i++){
            if (nums[i] % 2 == 0){
                sum += nums[i];
            }
        }
        for (int i = 0; i < q; i++){
            if (nums[queries[i][1]] % 2 == 0){
                sum -= nums[queries[i][1]];
            }
            nums[queries[i][1]] += queries[i][0];
            if (nums[queries[i][1]] % 2 == 0){
                sum += nums[queries[i][1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};