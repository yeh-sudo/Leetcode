class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> ans;
        for (int i = 0; i < words.size(); i++){
            string s = "";
            for (int j = 0; j < words[i].size(); j++){
                s += morse[words[i][j]-'a'];
            }
            ans.insert(s);
        }
        return (int)ans.size();
    }
};