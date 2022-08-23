/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        ListNode* cur = head;
        while (cur != NULL){
            a.push_back(cur->val);
            cur = cur->next;
        }
        if (a.size() % 2 == 0){
            int l = a.size() / 2 - 1;
            int r = l + 1;
            while (l >= 0 && r < a.size()){
                if (a[l] != a[r]) return 0;
                l--, r++;
            }
        }
        else {
            int l = a.size() / 2 - 1;
            int r = l + 2;
            while (l >= 0 && r < a.size()){
                if (a[l] != a[r]) return 0;
                l--, r++;
            }
        }
        return 1;
    }
};