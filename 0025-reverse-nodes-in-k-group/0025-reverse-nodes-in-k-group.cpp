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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode * p = head;
        while(p){
            n++;
            p = p -> next;
        }
        int t = n / k;
        p = head;
        ListNode * q = 0, * r = 0, *tail = 0, *pretail;
        bool flag = true;
        while(t--){
            int some = k;
            pretail = tail;
            tail = p;
            while(some--){
                r = q;
                q = p;
                p = p -> next;
                q -> next = r;
            }
            if(flag){
                head = q;
                flag = false;
            }else
                pretail -> next = q;
        }
        tail -> next = p;
        return head;
    }
};