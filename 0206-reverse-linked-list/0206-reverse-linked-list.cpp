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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode*q = 0, * r= 0, *temp=0;
        while(head){
            temp = head;
            head = head -> next;
        }
        reverse(p,q,r);
        return temp;
    }
    void reverse(ListNode*p, ListNode * q, ListNode*r){
        if(p == 0) return ;
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        reverse(p, q, r);
    }
};