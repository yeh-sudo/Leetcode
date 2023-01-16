class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }
        bool add = 0;
        int l = INT_MAX, r = 0;
        if (intervals[0][0] > newInterval[1]){
            add = 1;
            ans.push_back(newInterval);
        }
        for (int i = 0; i < intervals.size(); i++){
            int s = intervals[i][0], e = intervals[i][1];
            if (e < newInterval[0] || s > newInterval[1]){
                ans.push_back({s, e});
                if ((i == intervals.size() - 1 && !add) || (!add && i != intervals.size() - 1 && intervals[i+1][0] > newInterval[1])){
                    add = 1;
                    ans.push_back(newInterval);
                }
            } else {
                add = 1;
                l = min({l, newInterval[0], s});
                r = max({r, newInterval[1], e});
                if ((i != intervals.size() - 1 && intervals[i+1][0] > newInterval[1]) || i == intervals.size() - 1){
                    ans.push_back({l, r});
                }
            }
        }
        return ans;
    }
};