class Solution {
public:
    
    vector<string> ans;
    int mxN;
    
    void rec(string s, int open, int close){
        if (open == close && open == mxN){
            ans.push_back(s);
            return;
        }
        if (open == close){
            string tmp = s + '(';
            rec(tmp, open + 1, close);
        }
        else {
            if (open == mxN){
                string tmp = s + ')';
                rec(tmp, open, close + 1);
            }
            else {
                string tmp1 = s + '(';
                string tmp2 = s + ')';
                rec(tmp1, open + 1, close);
                rec(tmp2, open, close + 1);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        mxN = n;
        string s = "(";
        rec(s, 1, 0);
        return ans;
    }
};