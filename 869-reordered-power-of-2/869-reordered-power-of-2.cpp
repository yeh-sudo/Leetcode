class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        do {
            if (s[0] == '0') continue;
            int tmp = stoi(s);
            double k = log2(tmp);
            int t = k;
            if (k == t){
                return 1;
            }
        } while (next_permutation(s.begin(), s.end()));
        return 0;
    }
};