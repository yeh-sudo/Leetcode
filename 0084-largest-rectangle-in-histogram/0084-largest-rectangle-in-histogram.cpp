class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int ans = 0, idx = 0;
        for (int i = 0; i < heights.size(); i++){
            if (idx != i){
                s.push({idx, heights[i]});
            } else {
                s.push({i, heights[i]});
            }
            idx = i + 1;
            if (i == heights.size() - 1){
                break;
            }
            if (heights[i] > heights[i+1]){
                idx = s.top().first;
                while (!s.empty() && s.top().second >= heights[i+1]){
                    idx = s.top().first;
                    ans = max(ans, (i + 1 - s.top().first) * s.top().second);
                    s.pop();
                }
            }
        }
        while (!s.empty()){
            ans = max(ans, ((int)heights.size() - s.top().first) * s.top().second);
            s.pop();
        }
        return ans;
    }
};