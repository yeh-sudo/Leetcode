class Solution {
public:
    bool isValid(string s) {
        stack<char> aprs;
            for (int i = 0; i < s.size(); i++){
                if ((aprs.size() != 0) && ((aprs.top() == '(' && s[i] == ')') || (aprs.top() == '[' && s[i] == ']') || (aprs.top() == '{' && s[i] == '}'))){
                    aprs.pop();
                }
                else {
                    aprs.push(s[i]);
                }
            }
            if (aprs.empty())
                return true;
            else 
                return false;
    }
};