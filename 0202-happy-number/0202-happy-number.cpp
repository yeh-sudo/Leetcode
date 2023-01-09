class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while (n != 1){
            int k = n;
            int sum = 0;
            while (k != 0){
                int d = k % 10;
                sum += d * d;
                k /= 10;
            }
            if (s.count(sum)){
                return 0;
            }
            s.insert(sum);
            n = sum;
        }
        return 1;
    }
};