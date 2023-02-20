class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m + n);
        int p1 = 0, p2 = 0, ptr = 0;
        while (p1 < m || p2 < n){
            if (p1 == m){
                ans[ptr++] = nums2[p2++];
            } else if (p2 == n){
                ans[ptr++] = nums1[p1++];
            } else {
                if (nums1[p1] <= nums2[p2]){
                    ans[ptr++] = nums1[p1++];
                } else {
                    ans[ptr++] = nums2[p2++];
                }
            }
        }
        swap(ans, nums1);
    }
};