
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head, *fast  = head, * r = 0;
        while(fast and fast -> next){
            r = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(r)
            r -> next = NULL;
        r = 0;
        ListNode* q = 0;
        while(slow){
            q = r;
            r = slow;
            slow = slow -> next;
            r -> next = q;
        }
        while(r and head){
            if(r -> val != head -> val) return 0;
            r = r -> next;
            head = head -> next;
        }
        return true;
    }
};