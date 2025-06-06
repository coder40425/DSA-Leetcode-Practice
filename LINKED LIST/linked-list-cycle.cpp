/* Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 
Example 1:
Input: head = [3,2,0,-4], pos = 1   (last node's next is pointing to second node i.e index 1)
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
  
Example 2:
Input: head = [1,2], pos = 0    (2nd node's next is pointing to 1st node) 
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
  
Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


APPROACH:-
-WE WILL USE FLOYD'S CYCLE DETECTION ALGORITHM (ALSO CALLED TORTOISE AND HARE ALGORITHM)
-MAKE TWO POINTERS (FAST & SLOW) AND POINT THEM TO THE HEAD.
-SLOW WILL TRAVERSE WITH 1 STEP AT A TIME (SLOW = SLOW->NEXT)
-FAST WILL TRAVERSE WITH 2 STEPS AT A TIME (FAST = FAST->NEXT->NEXT)
-IF THEY MEET DURING THEIR TRAVERSAL (i.e IF SLOW == FAST), THEN RETURN TRUE.
-OTHERWISE RETURN FALSE.


       TIME COMPLEXITY:- O(N)
       SPACE COMPLEXITY:- O(1)                                                                                                      */



class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=nullptr && fast->next!=nullptr){       // IF ITS ACTUALLY A LINKED LIST CYCLE, THEN THERE WILL BE NO NULL POINTER IN THE LIST.
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
