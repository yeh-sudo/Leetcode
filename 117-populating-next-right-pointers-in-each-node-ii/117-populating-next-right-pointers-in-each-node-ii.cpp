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
            return NULL;
        }
        
        queue<int> dep;
        queue<Node*> q;
        q.push(root);
        dep.push(1);
        while (!q.empty()){
            Node* cur = q.front();
            int d = dep.front();
            dep.pop();
            q.pop();
            if (!q.empty() && d == dep.front()){
                cur->next = q.front();
            }
            if (cur->left != NULL){
                int next_d = d + 1;
                dep.push(next_d);
                q.push(cur->left);
            }
            if (cur->right != NULL){
                int next_d = d + 1;
                dep.push(next_d);
                q.push(cur->right);
            }
        }
        return root;
    }
};