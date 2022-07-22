
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        int len = 1;
        ListNode* curr = head;
        //get length of LL
        while(curr->next){
            len++;
            curr = curr->next;
        }

        //point last node to head
        curr->next = head;
        //
        k = k%len;
        k = len - k; //for getting kth node from the back
        while(k--) curr = curr->next; //now curr is standing kth node from end of list
        head = curr->next; //assign new head 
        curr->next = NULL;

        return head;
    }
};
