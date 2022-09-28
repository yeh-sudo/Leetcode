class MyCircularQueue {
    vector<int> q;
    int f, r;
    int s;
public:
    MyCircularQueue(int k) {
        q.resize(k, -1);
        f = 0, r = 0, s = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return 0;
        if (isEmpty()){
            q[r] = value;
            return 1;
        }
        q[(++r)%s] = value;
        r %= s;
        return 1;
    }
    
    bool deQueue() {
        if (isEmpty()) return 0;
        if (f == r){
            q[f] = -1;
            return 1;
        }
        q[f++] = -1;
        f %= s;
        return 1;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[f];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        if (f == r && q[f] == -1) return 1;
        return 0;
    }
    
    bool isFull() {
        if ((r + 1) % s == f && q[r] != -1) return 1;
        // if (r == s - 1 && f == 0) return 1;
        return 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */