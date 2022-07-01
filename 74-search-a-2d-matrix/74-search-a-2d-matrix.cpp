class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = (int)matrix.size() - 1;
        int s = 0;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target){
                s = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        l = 0; r = (int)matrix[s].size() - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (matrix[s][mid] == target){
                return true;
            }
            else if (matrix[s][mid] < target){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};