#define mod (int)(1e9 + 7)
#define ll long long

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        ll maxh = horizontalCuts[0], maxw = verticalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++){
            maxh = max(maxh, (ll)horizontalCuts[i] - (ll)horizontalCuts[i-1]);
        }
        for (int i = 1; i < verticalCuts.size(); i++){
            maxw = max(maxw, (ll)verticalCuts[i] - (ll)verticalCuts[i-1]);
        }
        maxh = max(maxh, (ll)h - (ll)horizontalCuts[horizontalCuts.size()-1]);
        maxw = max(maxw, (ll)w - (ll)verticalCuts[verticalCuts.size()-1]);
        ll ans = (maxh % mod) * (maxw % mod);
        return ans % mod;
    }
};