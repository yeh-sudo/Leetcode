class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26) return 0;
        vector<int> c(26, 0);
        for (int i = 0; i < sentence.size(); i++){
            c[sentence[i]-'a']++;
        }
        bool ans = 1;
        for (int i = 0; i < 26; i++){
            ans &= (c[i] > 0);
        }
        return ans;
    }
};