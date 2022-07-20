//-----------------------approach 1---------------------------
bool detectCycle(Node *head)
{
    unordered_set<Node*>set;
    while(head != NULL){
        if(set.find(head) != set.end()) return true;
        set.insert(head);
        head = head->next;
    }
    return false;
}

//-----------------------approach 2---------------------------
bool detectCycle(Node *head)
{   
    Node *slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
