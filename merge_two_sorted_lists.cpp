// leetcode - easy

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* res = new ListNode();
        ListNode* temp = res;
        
        while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                res->next = head1;
                res = res->next;
                head1 = head1->next;
            }
            else{
                res->next = head2;
                res = res->next;
                head2 = head2->next;
            }
        }
        while(head1 != NULL){
            res->next = head1;
            res = res->next;
            head1 = head1->next;
        }
        while(head2 != NULL){
            res->next = head2;
            res = res->next;
            head2 = head2->next;
        }
        return temp->next;
    }
};
