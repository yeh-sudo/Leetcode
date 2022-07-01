class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0){
                return 0;
            }
            if (haystack.size() == 0){
                return -1;
            }
            int pos = 0;
            bool check = true;
            for (int i = 0; i < haystack.size(); i++){
                check = true;
                for (int j = 0; j < needle.size(); j++){
                    if (haystack[i+j] != needle[j]){
                        check = false;
                        break;
                    }
                }
                if (check)
                    break;
                pos++;
            }
            if (!check){
                return -1;
            }
            return pos;
    }
};