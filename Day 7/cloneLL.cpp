//-----------------------approach 1 ---------------------

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>cp;
        
        Node *temp = head;
        while(temp){
            cp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp){
            cp[temp]->next = cp[temp->next];
            cp[temp]->random = cp[temp->random];
            temp = temp->next;
        }
        
        return cp[head];
    }
};

//-----------------------approach 2 ---------------------

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *curr = head, *nex = head;
        //1. insert copy nodes between two nodes of original list
        while(curr){
            nex = curr->next;
            Node *copy = new Node(curr->val);
            curr->next = copy;
            copy->next = nex;
            curr = nex;
        }
        
        //2. set random pointer of copy nodes
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        //3. set the next ptrs of copy list's nodes to point copy nodes
        //similarly set original list's nodes to point original nodes
        
        curr = head; //to traverse original list
        Node *copyhead = new Node(0);
        Node* copycurr = copyhead; //to traverse copy list
        
        while(curr){
            nex = curr->next->next;
            copycurr->next = curr->next;
            curr->next = nex;
            curr = curr->next;
            copycurr = copycurr->next;
        }
        return copyhead->next;
    }
};
