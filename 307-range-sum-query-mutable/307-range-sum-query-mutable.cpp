class NumArray {
    int n;
    vector<int> v;
    vector<int> tree;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < nums.size(); i++){
            v.push_back(nums[i]);
        }
        tree.resize(4 * n + 1);
        build(1, 0, n);
    }
    
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
    
    void update(int index, int val) {
        modify(index, val, 1, 0, n);
    }
    
    int query(int x, int y, int idx, int l, int r){
        if (x >= r || l >= y) return 0;
        if (x <= l && r <= y) return tree[idx];
        int mid = l + (r - l) / 2;
        return query(x, y, 2 * idx, l, mid) + query(x, y, 2 * idx + 1, mid, r);
    }
    
    int sumRange(int left, int right) {
        return query(left, right+1, 1, 0, n);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */