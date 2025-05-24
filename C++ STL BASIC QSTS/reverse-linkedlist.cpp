class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* ptr = head;
    ListNode* next = nullptr;

    while (ptr != nullptr) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    return prev; // New head of reversed list
}
};
