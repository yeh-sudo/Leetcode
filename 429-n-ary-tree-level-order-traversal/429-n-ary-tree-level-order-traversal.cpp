/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        map<int, vector<int>> tmp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()){
            Node* cur = q.front().first;
            int level = q.front().second;
            q.pop();
            tmp[level].push_back(cur->val);
            for (int i = 0; i < cur->children.size(); i++){
                q.push({cur->children[i], level+1});
            }
        }
        vector<vector<int>> ans;
        for (auto v : tmp){
            ans.push_back(v.second);
        }
        return ans;
    }
};