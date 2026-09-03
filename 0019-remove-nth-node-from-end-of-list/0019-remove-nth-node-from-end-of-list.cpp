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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* a= head;
        int count=0;
        //base case
        while(a!=NULL){
            a=a->next;
            count++;
        }
        // from start
        n = count-n-1;
        if(n==-1){
            head=head->next;
            delete a;
            return head;
        }
        a=head;
        while(n--) a=a->next;
        ListNode * b =a->next;
        a->next=b->next;
        delete b;
        return head;
        
        
    }
};