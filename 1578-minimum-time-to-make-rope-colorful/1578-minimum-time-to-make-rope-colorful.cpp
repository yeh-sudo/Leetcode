class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size();
        priority_queue<int> pq;
        char cur = colors[0];
        for (int i = 0; i < n; i++){
            if (cur == colors[i]){
                pq.push(neededTime[i]);
            }
            else {
                cur = colors[i];
                pq.pop();
                while (!pq.empty()){
                    ans += pq.top();
                    pq.pop();
                }
                pq.push(neededTime[i]);
            }
        }
        pq.pop();
        while (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};