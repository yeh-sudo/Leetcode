class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;
            int add = 1;
            for (int i = digits.size() - 2; i >= 0; i--){
                if (add == 0){
                    break;
                }
                if (digits[i+1] == 10){
                    digits[i+1] %= 10;
                    digits[i] += add;
                    continue;
                }
                if (digits[i+1] != 10)
                    add = 0;
            }
            if (digits[0] == 10){
                digits[0] %= 10;
                digits.insert(digits.begin(), 1);
            }
            return digits;
    }
};