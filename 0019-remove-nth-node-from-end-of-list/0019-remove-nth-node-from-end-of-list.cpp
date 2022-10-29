
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * t = head, * pre = NULL, * p = head;
        while(n--){
            t = t -> next;
        }
        
        while(t){
            pre = p;
            p = p->next;
            t = t->next;
        }
        if(!pre) return head -> next;
        pre -> next = p -> next;
        delete(p);
        return head;
    }
};