class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int  ans=0;
        unordered_map<string,int> s;
        int n=words.size();
        int t=0;
        for(int i=0;i<n;i++){
            if(s[words[i]]>0){
                ans+=4;
                s[words[i]]--;
            }
            else{
                reverse(words[i].begin(),words[i].end());
                s[words[i]]++;
            }
        }
        for(auto p:s){
            if(p.second>0 && p.first[0]==p.first[1])
                t=2;
        }
        ans+=t;
        return ans;
    }
};