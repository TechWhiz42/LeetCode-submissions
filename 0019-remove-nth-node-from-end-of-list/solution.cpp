class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        int pos = size - n;

        if (pos == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        return head;
    }
};
