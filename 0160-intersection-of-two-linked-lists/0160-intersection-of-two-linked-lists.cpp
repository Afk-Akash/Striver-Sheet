/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode *  p = a, * q = b;
        while(a != b){
            if(a == 0) a = q;
            else a = a -> next;
            if(b == 0)b = p;
            else b = b -> next;
            
        }
        return a;
    }
};