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
    void merge(vector<ListNode*>& lists, int l, int mid, int r){
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        head->next = NULL;
        ListNode* ptrL = lists[l];
        ListNode* ptrR = lists[mid+1];
        while (ptrL != NULL || ptrR != NULL){
            if (ptrL == NULL && ptrR != NULL){
                ptr->next = ptrR;
                ptrR = ptrR->next;
                ptr = ptr->next;
            } else if (ptrL != NULL && ptrR == NULL){
                ptr->next = ptrL;
                ptrL = ptrL->next;
                ptr = ptr->next;
            } else {
                if (ptrL->val <= ptrR->val){
                    ptr->next = ptrL;
                    ptr = ptr->next;
                    ptrL = ptrL->next;
                } else {
                    ptr->next = ptrR;
                    ptr = ptr->next;
                    ptrR = ptrR->next;
                }
            }
        }
        lists[l] = head->next;
    }
    void mergeSort(int l, int r, vector<ListNode*>& lists){
        if (l < r){
            int mid = l + (r - l) / 2;
            mergeSort(l, mid, lists);
            mergeSort(mid + 1, r, lists);
            merge(lists, l, mid, r);
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0){
            return NULL;
        }
        mergeSort(0, lists.size()-1, lists);
        return lists[0];
    }
};