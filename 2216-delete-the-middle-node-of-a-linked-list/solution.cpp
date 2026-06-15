class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int pos = n / 2;

        ListNode* prev = head;

        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }

        ListNode* nodeToDelete = prev->next;

        prev->next = nodeToDelete->next;

        return head;
    }
};
