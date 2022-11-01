
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head , * fast = head;
        while(fast and fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)break;
        }
        if(fast == 0 or !fast -> next) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};