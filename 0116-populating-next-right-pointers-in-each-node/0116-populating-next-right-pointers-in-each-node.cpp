/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL){
            return root;
        }
        queue<pair<int, Node*>> q;
        q.push({0, root});
        while (!q.empty()){
            pair<int, Node*> cur = q.front();
            q.pop();
            if (q.empty() || q.front().first != cur.first){
                cur.second->next = NULL;
            } else {
                cur.second->next = q.front().second;
            }
            if (cur.second->left != NULL){
                q.push({cur.first + 1, cur.second->left});
            }
            if (cur.second->right != NULL){
                q.push({cur.first + 1, cur.second->right});
            }
        }
        return root;
    }
};