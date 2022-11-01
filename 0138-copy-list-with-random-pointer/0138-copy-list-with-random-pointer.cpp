

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * p = head;
        while(p){
            Node * t = new Node(p -> val);
            t -> next = p -> next;
            p -> next = t;
            p = p -> next -> next;
        }
        p = head;
        while(p){
            auto t = p -> random;
            if(t){
                p-> next -> random = t -> next;
            }
            p = p -> next -> next;
        }
        p = head;
        Node * dummy = new Node(0), *temp = dummy;
        while(p){
            temp -> next = p -> next;
            p -> next = p -> next -> next;
            p = p -> next;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};