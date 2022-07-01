class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz = max(num1.length(), num2.length());
        vector<int> n1(sz, 0), n2(sz, 0);
        string ans = "";
        int idx = 0;
        for (int i = num1.length() - 1; i >= 0; i--){
            n1[idx] = num1[i] - '0';
            idx++;
        }
        idx = 0;
        for (int i = num2.length() - 1; i >= 0; i--){
            n2[idx] = num2[i] - '0';
            idx++;
        }
        int carry = 0;
        for (int i = 0; i < sz; i++){
            int sum = (n1[i] + n2[i] + carry) % 10;
            carry = (n1[i] + n2[i] + carry) / 10;
            ans += (char)(sum + (int)'0');
        }
        if (carry != 0){
            ans += (char)(carry + (int)'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};