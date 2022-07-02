class Solution {
public:
    int myAtoi(string s) {
        string str = "";
        bool neg = 0, enc = 0, enc1 = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '+' && !enc){
                neg = 0;
                enc = 1;
            }
            else if (s[i] == '-' && !enc){
                neg = 1;
                enc = 1;
            }
            else if (s[i] == ' ' && !enc) 
                continue;
            else if ((!isdigit(s[i]) && enc) || (!isdigit(s[i]) && !enc && s[i] != ' '))
                break;
            else {
                enc = 1;
                if (s[i] == '0' && !enc1){
                    continue;
                }
                str = s[i] + str;
                enc1 = 1;
            }
        }
        if (str.size() > 10){
            if (neg){
                return INT_MIN;
            }
            else {
                return INT_MAX;
            }
        }
        long long ans = 0;
        for (int i = 0; i < str.size(); i++){
            ans += (long long)(str[i] - '0') * pow(10, i);
        }
        if (neg){
            if (-ans < INT_MIN){
                return INT_MIN;
            }
            return -ans;
        }
        if (ans > INT_MAX){
            return INT_MAX;
        }
        return ans;
    }
};