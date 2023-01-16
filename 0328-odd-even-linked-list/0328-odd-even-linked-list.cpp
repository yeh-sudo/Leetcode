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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        ListNode *odd = head, *even, *tmp, *oddHead = head, *evenHead;
        if (head->next){
            evenHead = head->next;
            even = evenHead;
        }
        int n = 1;
        while (head){
            tmp = head->next;
            if (n % 2 == 1){
                if (n != 1){
                    odd->next = head;
                    odd = odd->next;
                }
            } else {
                if (n != 2){
                    even->next = head;
                    even = even->next;
                }
            }
            n++;
            head = tmp;
        }
        if (evenHead != NULL){
            even->next = NULL;
            odd->next = evenHead;
        }
        return oddHead;
    }
};