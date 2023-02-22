class Solution {
    bool checkValid(vector<int>& weights, int w, int days){
        int ptr = weights.size() - 1;
        int load = 0, cntDays = 0;
        while (ptr >= 0){
            if (weights[ptr] > w){
                return false;
            }
            if (load + weights[ptr] <= w){
                load += weights[ptr--];
            } else {
                cntDays++;
                load = 0;
            }
        }
        if (load != 0){
            cntDays++;
        }
        if (cntDays > days){
            return false;
        } else {
            return true;
        }
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++){
            sum += weights[i];
        }
        int l = 1, r = sum;
        int ans = sum;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (checkValid(weights, mid, days)){
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};