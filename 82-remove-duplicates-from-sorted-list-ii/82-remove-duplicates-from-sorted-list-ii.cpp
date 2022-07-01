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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        if (head->next == NULL){
            return head;
        }
        ListNode* cur = head;
        ListNode* res = new ListNode(10001);
        ListNode* ptr = res;
        bool c = false;
        while (cur != NULL){
            if (cur->next == NULL || cur->next->val != cur->val){
                if (c){
                    c = false;
                    cur = cur->next;
                    continue;
                }
                else {
                    ListNode* n = new ListNode(cur->val);
                    if (ptr->val == 10001){
                        ptr->val = cur->val;
                        c = false;
                        cur = cur->next;
                        continue;
                    }
                    ptr->next = n;
                    ptr = ptr->next;
                    c = false;
                }
            }
            else {
                c = true;
            }
            cur = cur->next;
        }
        if (res->val == 10001){
            return NULL;
        }
        return res;
    }
};