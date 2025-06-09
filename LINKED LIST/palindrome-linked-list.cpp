/* Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


Example 1:
Input: head = [1,2,2,1]
Output: true
  
Example 2:
Input: head = [1,2]
Output: false


#APPROACH:-
-WE WILL USE SLOW & FAST POINTER TECHNIQUE TO REACH THE MIDDLE OF THE LIST.
-SLOW: 1 STEP & FAST: 2 STEPS, WHEN FAST REACHES THE END OF THE LIST, SLOW WILL BE AT THE MIDDLE.
-ONCE MIDDLE IS FOUND, REVRSE THE SECOND HALF OF THE LIST.
-NOW COMPARE THE FIRST & THE SECOND HALVES.
-IF ALL THE VALUES MATCHED, RETURN TRUE, OTHERWISE FALSE.

     TIME COMPLEXITY: O(N)
     SPACE COMPLEXITY: O(1)                                                          */


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*ptr=slow;
        ListNode*prev=nullptr;
        ListNode*next=nullptr;
        
        while(ptr!=nullptr){
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
        }

        ListNode*first=head;
        ListNode*second=prev;

        while(second!=nullptr){
            if(first->val==second->val){
                first=first->next;
                second=second->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
