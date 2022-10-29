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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode * p = head;
        while(p){
            size++;
            p = p->next;
        }
        size -= n;
        p = head;
        ListNode* pre= NULL;
        while(size--){
            pre = p;
            p = p->next;
        }
        if(pre== NULL)return head->next;
        pre -> next = p -> next;
        delete(p);
        return head;
    }
};