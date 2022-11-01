/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* dummy = new Node(0), *p = head;
        Node * ptr = dummy;
        while(head){
            Node * t  = new Node(head -> val);
            ptr -> next = t;
            mp[head] = t;
            ptr = ptr -> next;
            head = head -> next;
        }
        mp[NULL] = NULL;
        head = p;
        Node* newHead = dummy -> next;
        while(head){
     
            auto ptr = mp[head -> random];
            newHead -> random = ptr;
            head = head -> next;
            newHead = newHead -> next;
        }

        return dummy -> next;
    }
};