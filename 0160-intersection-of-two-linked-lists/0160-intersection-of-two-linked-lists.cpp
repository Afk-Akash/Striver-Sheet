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
        int k = 0;
        while(a != b and k < 3){
            a = a -> next;
            b = b -> next;
            if( a == 0){
                a = q;
                k += 1;
            } 
            if(b == 0){
                b = p;
                k += 1;
            }
        }
        return a==b ? a : 0;
    }
};