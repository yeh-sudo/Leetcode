class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        int ptr = num.size() - 1;
        while (k != 0 && ptr >= 0){
            int add = k % 10;
            num[ptr] += add + carry;
            carry = num[ptr] / 10;
            num[ptr] %= 10;
            k /= 10;
            ptr--;
        }
        while (k != 0){
            int add = k % 10 + carry;
            num.insert(num.begin(), add % 10);
            k /= 10;
            carry = add / 10;
        }
        while (carry != 0 && ptr >= 0){
            num[ptr] += carry;
            carry = num[ptr] / 10;
            num[ptr] %= 10;
            ptr--;
        }
        if (carry != 0){
            num.insert(num.begin(), carry);
        }
        return num;
    }
};