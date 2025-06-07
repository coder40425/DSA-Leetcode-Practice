/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 
Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
  
Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
  
Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


#APPROACH:-
-CREATE A DUMMY NODE.
-INITIALIZE A POINTER CURRENT TO POINT TO DUMMY.
-INITIALIZE CARRY = 0.
-TRAVERSE BOTH LISTS SIMULTANEOUSLY.
-GET VALUES FROM L1 & L2.
-CALCULATE SUM ( SUM = VAL1 + VAL2 + CARRY) & UPDATE CARRY (CARRY = SUM/10).
-MOVE CURRENT POINTER FORWARD.
-MOVE L1 & L2 FORWARD IF THEY ARE NOT NULL.
-RETURN RESULT LIST.

     TIME COMPLEXITY:- O(max(N,M))     // N-> LENGTH OF L1 , M-> LENGTH OF L2
     SPACE COMPLEXITY:- O(max(N,M))                                                                            */


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = 0;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;      //RESULT LIST STARTS AFTER DUMMY, SO DUMMY'S NEXT IS THE HEAD PF THE FINAL LIST.
    }
};
 
