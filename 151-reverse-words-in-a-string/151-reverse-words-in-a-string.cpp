class Solution {
public:
    string reverseWords(string s) {
        stringstream ss{s};
        s.clear();
        string word;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            s += word + " ";
        }
        s.pop_back();
        return {s.rbegin(), s.rend()};
    }
};