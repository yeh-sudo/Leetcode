class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, bool> numsMap;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++){
                if (numsMap.find(nums[i]) == numsMap.end() || numsMap.empty()){
                    numsMap.insert(pair<int, bool>(nums[i], true));
                    cnt++;
                }
            }
            nums.clear();
            for (auto const& imap : numsMap){
                nums.push_back(imap.first);
            }
            return cnt;
    }
};