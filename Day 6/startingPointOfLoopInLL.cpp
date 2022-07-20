//-----------------------approach 1 ---------------------------
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>set;
        
        while(head){
            if(set.find(head) != set.end()) return head;
            set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

//-----------------------approach 2 ---------------------------

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *fast = head, *slow=head, *temp=head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                while(slow != temp){
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};
