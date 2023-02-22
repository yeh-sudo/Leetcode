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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        int c = 0;
        while (l1 != NULL || l2 != NULL){
            cur->val += l1->val + l2->val;
            if (cur->val >= 10){
                cur->val %= 10;
                c = 1;
            }
            else {
                c = 0;
            }
            if (l1->next != NULL || l2->next != NULL){
                cur->next = new ListNode(c);
                cur = cur->next;
            }
            if (l1->next != NULL && l2->next == NULL){
                l2->next = new ListNode(0);
            }
            else if (l1->next == NULL && l2->next != NULL){
                l1->next = new ListNode(0);
            }
            l1 = l1->next; l2 = l2->next;
        }
        if (c == 1){
            cur->next = new ListNode(c);
        }
        return res;
    }
};