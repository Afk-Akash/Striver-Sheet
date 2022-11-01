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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = 1;
        ListNode* p = head;
        while(p->next){
            n++;
            p = p -> next;
        }
        k %= n;
        if(k==0) return head;
        int copy = k+1;
        ListNode* fast = head, *slow = head;
        while(copy--){
            fast = fast -> next;
        }
        while(fast){
            fast = fast -> next;
            slow = slow -> next;
        }
        
        ListNode* temp = slow;
        slow = slow -> next;
        temp -> next = NULL;
        temp = slow;
     
        p -> next = head;
        return slow;
    }
};