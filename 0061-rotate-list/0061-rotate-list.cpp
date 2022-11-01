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
        int copy = n - k;
        ListNode* fast = head, *slow = head;
        while(--copy)slow = slow -> next;
        
        p -> next = head;
        head = slow -> next;
        slow -> next = NULL;
     
        return head;
    }
};