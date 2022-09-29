class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = idx-1, r = idx;
        while (k--){
            if (l >= 0 && r < arr.size()){
                if (abs(arr[l] - x) <= abs(arr[r] - x)){
                    l--;
                }
                else {
                    r++;
                }
            }
            else {
                if (l < 0){
                    r++;
                }
                else if (r >= arr.size()){
                    l--;
                }
            }
            // cout << l << ' ' << r << '\n';
        }
        l++, r--;
        vector<int> ans;
        for (int i = l; i <= r; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};