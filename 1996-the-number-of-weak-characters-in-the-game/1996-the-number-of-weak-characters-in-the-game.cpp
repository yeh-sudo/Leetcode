bool cmp(vector<int>& a, vector<int>& b){
    if (a[0] != b[0]) return a[0] > b[0];
    return a[1] < b[1];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int n = properties.size();
        int ans = 0;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++){
            if (mx > properties[i][1]) ans++;
            else mx = properties[i][1];
        }
        return ans;
    }
};