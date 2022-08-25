class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < magazine.size(); i++){
            cnt[magazine[i]-'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++){
            if (cnt[ransomNote[i]-'a'] > 0){
                cnt[ransomNote[i]-'a']--;
            }
            else {
                return 0;
            }
        }
        return 1;
    }
};