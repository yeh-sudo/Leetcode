class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string front = "";
        while(head){
            front += head->val;
            head = head->next;
        }
        string reverse_front = front;
        reverse(front.begin(), front.end());
        if(front == reverse_front)
            return true;
        return false;
    }
};