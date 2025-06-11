/* Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 
Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]                                                                      


#APPROACH:-
1. TRAVERSE FROM HEAD TO THE LEFT-TH NODE, KEEPING A POINTER TO THE NODE JUST BEFORE IT.
2. REVERSE THE NEXT RIGHT−LEFT+1 NODES BY ITERATIVELY FLIPPING THEIR NEXT POINTERS.
3. AFTER REVERSAL, CONNECT THE “NODE BEFORE SUBLIST” TO THE NEW SUBLIST HEAD.
4. CONNECT THE ORIGINAL SUBLIST TAIL TO THE NODE IMMEDIATELY AFTER THE RIGHT-TH NODE.
5. RETURN THE (POTENTIALLY UPDATED) HEAD OF THE LIST.

       TIME COMPLEXITY: O(N)
       SPACE COMPLEXITY: O(1)
                                                                                                   */


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
