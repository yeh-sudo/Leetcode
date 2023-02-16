class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()){
            return "";
        }
        vector<int> calRef(26, 0), ref(26, 0);
        for (int i = 0; i < t.size(); i++){
            if (isupper(t[i])){
                calRef[t[i]-'A']++;
            } else {
                ref[t[i]-'a']++;
            }
        }
        vector<int> calCheck(26, 0), check(26, 0);
        int l = 0, r = 1, ansL = -1, ansR = -1, len = INT_MAX;
        if (isupper(s[l])){
            calCheck[s[l]-'A']++;
        } else {
            check[s[l]-'a']++;
        }
        while (l < r && (l != s.size() || r != s.size())){
            bool valid = true;
            for (int i = 0; i < 26; i++){
                if (calRef[i] > calCheck[i]){
                    valid = false;
                }
                if (ref[i] > check[i]){
                    valid = false;
                }
            }
            if (!valid){
                if (r != s.size()){
                    if (isupper(s[r])){
                        calCheck[s[r]-'A']++;
                    } else {
                        check[s[r]-'a']++;
                    }
                    r++;
                } else {
                    break;
                }
            } else {
                if (len > r - l){
                    ansL = l;
                    ansR = r;
                    len = r - l;
                }
                if (isupper(s[l])){
                    calCheck[s[l]-'A']--;
                } else {
                    check[s[l]-'a']--;
                }
                l++;
                if (l == r && r != s.size()){
                    r++;
                }
            }
            // cout << l << ' ' << r << ' ' << s.substr(l, r - l) << ' ' << valid << '\n';
        }
        // cout << ansL << ' ' << ansR;
        if (ansL == -1 || ansL == -1){
            return "";
        }
        return s.substr(ansL, ansR - ansL);
    }
};