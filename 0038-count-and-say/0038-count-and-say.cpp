class Solution {
public:
    string countAndSay(int n) {
        int idx = 0;
        string str = "1";
        while (1){
            if (idx + 1 == n){
                break;
            }
            string tmp = "";
            int cnt = 0;
            for (int i = 0; i < str.size(); i++){
                cnt++;
                if (i < str.size() - 1 && str[i] != str[i+1]){
                    tmp += to_string(cnt) + str[i];
                    cnt = 0;
                }
            }
            tmp += to_string(cnt) + str[str.size() - 1];
            str = tmp;
            idx++;
        }
        return str;
    }
};