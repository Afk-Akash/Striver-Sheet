
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode * p = head;
        while(p){
            n++;
            p = p -> next;
        }
        int t = n - n % k;
        ListNode * q = 0, * r = 0,*start = 0;
        p = head;
        while(t--){
            r = q;
            q = p;
            p = p -> next;
            q -> next = r;
        }
        head = p;
        t = n / k;
        while(t--){
            start = head;
            head = q;
            int some = k;
            while(some--){
                r = q;
                q = q -> next;
            }
            r -> next = start;
        }
        return head;
    }
};