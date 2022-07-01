class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        int n = num1.length() + num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> mult(n, 0);
        for (int i = 0; i < num1.length(); i++){
            for (int j = 0; j < num2.length(); j++){
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                mult[i + j] += d1 * d2;
            }
        }
        int carry = 0;
        for (int i = 0; i < n; i++){
            int sum = (mult[i] + carry) % 10;
            carry = (mult[i] + carry) / 10;
            mult[i] = sum;
        }
        bool lead_zero = true;
        for (int i = n - 1; i >= 0; i--){
            if (lead_zero){
                if (mult[i] != 0){
                    lead_zero = false;
                    ans += (char)(mult[i] + (int)'0');
                }
                continue;
            }
            ans += (char)(mult[i] + (int)'0');
        }
        if (ans == ""){
            ans = "0";
        }
        return ans;
    }
};