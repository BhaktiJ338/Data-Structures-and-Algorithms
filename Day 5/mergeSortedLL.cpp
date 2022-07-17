//approach 1

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *head = new Node<int>(-1);
    Node<int> *res = head;
    while(first != NULL && second != NULL){
        if(first->data <= second->data){
            head->next = first;
            first = first->next;
        }
        else{
            head->next = second;
            second = second->next;
        }
        head = head->next;
    }
    
    if(first != NULL) head->next = first;
    if(second != NULL) head->next = second;
    
    return res->next;
}

//approach 2

Node<int>* sortTwoLists(Node<int>* head1, Node<int>* head2)
{
        if(!head1) return head2;
        if(!head2) return head1;
        
        if(head1->data > head2->data) swap(head1, head2);
        Node<int> *newHead = head1;
        
        while(head1 && head2){
            Node<int> *temp = NULL;
            while(head1 && head1->data <= head2->data){
                temp = head1;
                head1 = head1->next;
            }
            temp->next = head2;
            swap(head1, head2);
        }
        return newHead;
}

