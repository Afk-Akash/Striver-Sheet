
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode* p = dummy;
        int carry = 0;
        
        while(l1 or l2){
            int temp = carry;
            if(l1){
                 temp += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                temp += l2 -> val;
                l2 = l2 -> next;
            }
            
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
        }

        if(carry) p -> next = new ListNode(1,NULL);
        return dummy->next;
    }
};