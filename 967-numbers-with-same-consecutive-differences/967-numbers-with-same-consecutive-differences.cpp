class Solution {
    vector<int> ans;
    void dfs(int n, int k, int len, string num){
        if (n == len){
            ans.push_back(stoi(num));
            return;
        }
        if ((char)(num[len-1] + k) <= '9' && k != 0){
            dfs(n, k, len + 1, num + (char)(num[len-1] + k));
        }
        if ((char)(num[len-1] - k) >= '0'){
            dfs(n, k, len + 1, num + (char)(num[len-1] - k));
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        string tmp = "";
        for (int i = 1; i <= 9; i++){
            tmp += (char)(i + '0');
            dfs(n, k, 1, tmp);
            tmp.pop_back();
        }
        return ans;
    }
};