class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int m = intervals[0][0], M = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++){
            vector<int> tmp;
            if (intervals[i][0] > M){
                tmp.push_back(m);
                tmp.push_back(M);
                ans.push_back(tmp);
                m = intervals[i][0];
                M = intervals[i][1];
            }
            else {
                m = min(m, intervals[i][0]);
                M = max(M, intervals[i][1]);
            }
        }
        vector<int> tmp;
        tmp.push_back(m);
        tmp.push_back(M);
        ans.push_back(tmp);
        return ans;
    }
};