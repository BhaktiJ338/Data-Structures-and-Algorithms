////////////////////////approach 1//////////////////////

int findIntersection(Node *h1, Node *h2)
{
    if(!h1 || !h2) return -1;
    Node *l1 = h1;
    Node *l2 = h2;
    while(l1){
        Node *temp = l2;
        while(temp){
            if(l1 == temp) return l1->data;
            temp = temp->next;
        }
        l1 = l1->next;
    }
    return -1;
}

///////////////////////////approach 2///////////////////////

int findIntersection(Node *h1, Node *h2)
{
    if(!h1 || !h2) return -1;
    unordered_set<Node*>mp;
    Node* l1 = h1;
    Node* l2 = h2;
    while(l1){
        mp.insert(l1);
        l1 = l1->next;
    }
    while(l2){
        if(mp.find(l2) != mp.end()) return l2->data;
        l2 = l2->next;
    }
    return -1;
}

//////////////////////////approach 3.1//////////////////////

int findIntersection(Node *h1, Node *h2)
{
    if(!h1 || !h2) return -1;
    unordered_map<Node*, Node*>mp;
    Node* l1 = h1;
    Node* l2 = h2;
    int c1=0, c2=0;
    while(l1){
        c1++;
        l1 = l1->next;
    }
    while(l2){
        c2++;
        l2 = l2->next;
    }
    Node *d1, *d2;
    if(c1 > c2){
        d1 = h1;
        d2 = h2;
    }
    else{
        d1 = h2;
        d2 = h1;
    }
    for(int i=0; i<abs(c1-c2); i++){
        d1 = d1->next;
    }
    while(d1){
        if(d1 == d2) return d1->data;
        d1 = d1->next;
        d2 = d2->next;
    }
    return -1;
}

/////////////////////////approach 3.2//////////////////////

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        
        while(l1 != l2){
            l1 = !l1 ? l1 = headA : l1 = l1->next;
        	l2 = !l2 ? l2 = headB : l2 = l2->next;
        }
        return l1;
    }
};
