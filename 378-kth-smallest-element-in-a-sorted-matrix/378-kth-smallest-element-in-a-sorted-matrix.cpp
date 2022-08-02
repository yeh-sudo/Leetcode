class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                pq.push(matrix[i][j]);
            }
        }
        while (pq.size() != k){
            pq.pop();
        }
        ans = pq.top();
        return ans;
    }
};