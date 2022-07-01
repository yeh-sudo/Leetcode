class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans, tmp;
        ans.push_back(1);
        if (rowIndex == 0){
            return ans;
        }
        for (int i = 1; i <= rowIndex; i++){
            tmp.clear();
            tmp.push_back(1);
            for (int j = 1; j < i; j++){
                tmp.push_back(ans[j] + ans[j-1]);
            }
            tmp.push_back(1);
            ans = tmp;
        }
        return ans;
    }
};