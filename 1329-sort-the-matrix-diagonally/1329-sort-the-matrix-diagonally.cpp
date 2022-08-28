class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++){
            vector<int> tmp;
            for (int k = 0; i + k < n && k < m; k++){
                tmp.push_back(mat[i + k][k]);
            }
            sort(tmp.begin(), tmp.end());
            for (int k = 0; i + k < n && k < m; k++){
                mat[i+k][k] = tmp[k];
            }
        }
        for (int i = 0; i < m; i++){
            vector<int> tmp;
            for (int k = 0; i + k < m && k < n; k++){
                tmp.push_back(mat[k][i+k]);
            }
            sort(tmp.begin(), tmp.end());
            for (int k = 0; i + k < m && k < n; k++){
                mat[k][i+k] = tmp[k];
            }
        }
        return mat;
    }
};