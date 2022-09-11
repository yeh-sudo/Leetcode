#define ll long long
const long long mod = 1e9 + 7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ll ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        ll spd = 0;
        for (int i = 0; i < n; i++){
            ll s = v[i].second, e = v[i].first;
            if (pq.size() >= k){
                ll tmp = pq.top();
                spd -= tmp;
                pq.pop();
            }
            spd += s;
            pq.push(s);
            ans = max(ans, e * spd);
        }
        return ans % mod;
    }
};