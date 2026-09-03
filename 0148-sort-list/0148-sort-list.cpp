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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
    ListNode* sortList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* mid=findMid(head);
        ListNode* nextnode=mid->next;
        mid->next=NULL;
        ListNode* head1=sortList(head);
        ListNode* head2=sortList(nextnode);

        ListNode dummy(0);
        ListNode* curr=&dummy;

        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                curr->next=head1;
                head1=head1->next;
            } else{
                curr->next=head2;
                head2=head2->next;
            }
            curr = curr->next;

        }
        if(head1){
            curr->next=head1;
        }else
            curr->next=head2;
        return dummy.next;
    }
};