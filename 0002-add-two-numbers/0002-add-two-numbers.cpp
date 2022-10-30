
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode* p = dummy;
        int carry = 0;
        
        while(l1 and l2){
            int temp = l1 -> val + l2 -> val + carry;
            
            if(temp <= 9){
                ListNode* t = new ListNode(temp);
                p -> next = t;
                p = p -> next;
                carry = 0;
            }else{
                ListNode* t= new ListNode(temp%10);
                p -> next = t;
                p = p -> next;
                carry = 1;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if(l1){
            while(l1){
                int temp = l1 -> val + carry;
                if(temp <= 9){
                    p -> next = new ListNode(temp);
                    p = p->next;
                    carry = 0;
                }else{
                    p ->next = new ListNode(temp%10);
                    p = p -> next;
                    carry = 1;
                }
                l1 = l1 ->  next;
            }
            
        }
         if(l2){
            while(l2){
                int temp = l2 -> val + carry;
                if(temp <= 9){
                    p -> next = new ListNode(temp);
                    p = p->next;
                    carry = 0;
                }else{
                    p ->next = new ListNode(temp%10);
                    p = p -> next;
                    carry = 1;
                }
                l2 = l2 ->  next;
            }
            
        }
        if(carry) p -> next = new ListNode(1,NULL);
        return dummy->next;
    }
};