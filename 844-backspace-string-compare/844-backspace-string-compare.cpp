class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string cmp1 = "", cmp2 = "";
        stack<char> s1, s2;
        for (int i = 0; i < s.length(); i++){
            if (s1.empty()){
                if (s[i] == '#'){
                    continue;
                }
                else {
                    s1.push(s[i]);
                }
            }
            else {
                if (s[i] == '#'){
                    s1.pop();
                }
                else {
                    s1.push(s[i]);
                }
            }
        }
        for (int i = 0; i < t.length(); i++){
            if (s2.empty()){
                if (t[i] == '#'){
                    continue;
                }
                else {
                    s2.push(t[i]);
                }
            }
            else {
                if (t[i] == '#'){
                    s2.pop();
                }
                else {
                    s2.push(t[i]);
                }
            }
        }
        while (!s1.empty()){
            cmp1 += s1.top();
            s1.pop();
        }
        while (!s2.empty()){
            cmp2 += s2.top();
            s2.pop();
        }
        if (cmp1 == cmp2){
            return true;
        }
        else {
            return false;
        }
    }
};