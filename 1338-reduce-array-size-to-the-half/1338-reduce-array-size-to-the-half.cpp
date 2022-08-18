class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++){
            cnt[arr[i]]++;
        }
        vector<pair<int, int>> v;
        copy(cnt.begin(), cnt.end(), back_inserter<vector<pair<int, int>>>(v));
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        int ans = 0;
        int m = n;
        for (int i = 0; i < v.size(); i++){
            if (m - v[i].second <= n / 2){
                ans++;
                break;
            }
            else {
                ans++;
                m -= v[i].second;
            }
        }
        return ans;
    }
};