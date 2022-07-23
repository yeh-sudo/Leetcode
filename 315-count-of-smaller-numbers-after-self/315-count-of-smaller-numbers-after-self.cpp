class Solution {
public:
    vector<int> v;
    vector<long long> tree;

    void build(int idx, int l, int r){
        if (l + 1 == r){
            tree[idx] = v[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid, r);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
    
    void modify(int p, int x, int idx, int l, int r){
        if (l + 1 == r){
            v[p] = x;
            tree[idx] = x;
            return;
        }
        int mid = l + (r - l) / 2;
        if (p < mid){
            modify(p, x, 2 * idx, l, mid);
        }
        else {
            modify(p, x, 2 * idx + 1, mid, r);
        }
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
    
    int query(int x, int y, int idx, int l, int r){
        if (x >= r || l >= y) return 0;
        if (x <= l && r <= y) return tree[idx];
        int mid = l + (r - l) / 2;
        return query(x, y, 2 * idx, l, mid) + query(x, y, 2 * idx + 1, mid, r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        v.resize(n+1, 0);
        tree.resize(4 * n + 1);
        vector<int> tmp = nums, cnt(n);
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; i++){
            cnt[i] = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
        }
        for (int i = n - 1; i >= 0; i--){
            ans[i] = query(0, cnt[i], 1, 0, n);
            modify(cnt[i], v[cnt[i]]+1, 1, 0, n);
        }
        return ans;
    }
};