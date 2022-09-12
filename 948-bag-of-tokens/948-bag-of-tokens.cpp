class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0, score = 0, n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int l = 0, r = n - 1;
        while (l <= r){
            if (power - tokens[l] < 0){
                if (score <= 0){
                    break;
                }
                power += tokens[r--];
                score--;
                ans = max(ans, score);
            }
            else {
                power -= tokens[l++];
                score++;
                ans = max(ans, score);
            }
        }
        return ans;
    }
};