class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();
            current->next = smallest; current = current->next;
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        } return dummy->next;
    }
};