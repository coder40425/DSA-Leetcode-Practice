/* Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
  
Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

#APPROACH:
-COUNT TOTAL NODES TO CHECK IF THERE ARE ATLEAST K NODES TO REVERSE.
-IF NOT, RETURN HEAD.
-REVERSE FIRST K NODES.
-PREV WILL POINT TO NEW HEAD.
-HEAD BECOMES TAIL OF REVERSED SEGMENT.
-PTR POINTS TO NEXT NODE AFTER THE REVERSED SEGMENT.
-RECURSIVE CALL ON REMAINING LIST.
-THE OLD HEAD'S NEXT IS CONNECTED TO THE HEA DOF THE REVERSED NEXT SEGMENT.

       TIME COMPLEXITY:- O(N)
       SPACE COMPLEXITY:- O(N/K)    //RECURSION STACK SPACE                                                                            */
      


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length=0;
        ListNode*temp=head;
        while(temp!=nullptr){
            length++;
            temp=temp->next;
        }
        if(length<k){
            return head;
        }
        ListNode*prev=nullptr;
            ListNode*ptr=head;
            ListNode*next=nullptr;
            int count=0;
        while(ptr!=nullptr && count<k){
                next=ptr->next;
                ptr->next=prev;
                prev=ptr;
                ptr=next;
                count++;
        }
            if(next!=nullptr){
                head->next=reverseKGroup(next,k);
            }
        return prev;
    }
};
