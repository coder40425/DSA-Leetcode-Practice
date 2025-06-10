/* Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 
Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]                                                                      */


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Move curr to the left-th node, prev just before it
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Reverse from left to right
        ListNode* last = prev;          // Node before sublist
        ListNode* newEnd = curr;        // Will become the end of reversed sublist
        ListNode* next = nullptr;

        for (int i = 0; i <= right - left; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Reconnect the reversed sublist back
        if (last != nullptr) {
            last->next = prev;
        } else {
            head = prev;
        }

        newEnd->next = curr;
        return head;
    }
};
