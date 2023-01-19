class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> m;
        for (int i = 0; i < tasks.size(); i++){
            m[tasks[i]-'A']++;
        }
        priority_queue<int> pq1, pq2;
        for (auto p : m){
            pq1.push(p.second);
        }
        int ans = 0, cnt = 0;
        while (!pq1.empty()){
            while (cnt != n + 1 && !pq1.empty()){
                ans++;
                cnt++;
                int cur = pq1.top();
                cout << cur << ' ';
                pq1.pop();
                cur--;
                if (cur != 0)
                    pq2.push(cur);
            }
            if (cnt != n + 1 && !pq2.empty()){
                ans += n + 1 - cnt;
            }
            while (!pq1.empty()){
                pq2.push(pq1.top());
                pq1.pop();
            }
            swap(pq2, pq1);
            cnt = 0;
        }
        return ans;
    }
};