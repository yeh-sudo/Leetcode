class Solution {
    map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    void comb(string str, int len, string digits){
        if (len == digits.size()){
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < m[digits[len]].size(); i++){
            str += m[digits[len]][i];
            comb(str, len + 1, digits);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return ans;
        }
        comb("", 0, digits);
        return ans;
    }
};