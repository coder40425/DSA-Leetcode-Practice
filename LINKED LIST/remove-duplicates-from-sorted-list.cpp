/* Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


Example 1:
Input: head = [1,1,2]
Output: [1,2]
  
Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]


#APPROACH:-
-INITIALIZE A POINTER PTR AT THE HEAD OF THE LINKED LIST.
-TRAVERSE THE LIST WHILE PTR IS NOT NULLPTR AND PTR->NEXT IS NOT NULLPTR.
-IF PTR->VAL == PTR->NEXT->VAL, SKIP THE NEXT NODE BY SETTING PTR->NEXT = PTR->NEXT->NEXT.
-OTHERWISE, MOVE PTR TO THE NEXT NODE.
-RETURN THE HEAD OF THE MODIFIED LIST.

           TIME COMPLEXITY: O(N)
           SPACE COMPLEXITY: O(1)                                                                                */


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return 0;
        }
        ListNode*k=head;
        ListNode*ptr=head->next;
        while(ptr!=nullptr){
            if(k->val!=ptr->val){
                k=k->next;
                ptr=ptr->next;
            }
            else{
                k->next=ptr->next;
                ptr=ptr->next;
            }
        }
        return head;

    }
};
