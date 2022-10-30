
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l2) return l1;
        if(!l1) return l2;
        ListNode * p = l1, * q = l2, *head = NULL;
     
        ListNode* t = new ListNode();
        head = t;
        while(p and q){
            if(p -> val < q -> val){
                t -> next = p;
                p = p->next;
                
            }else{
                t->next = q;
                q = q-> next;
            }
            t = t-> next;
        }
        if(p) t -> next = p;
        else t -> next = q;
        return head->next;
    }
};