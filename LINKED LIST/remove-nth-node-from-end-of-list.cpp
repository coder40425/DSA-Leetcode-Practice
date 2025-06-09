/* Given the head of a linked list, remove the nth node from the end of the list and return its head.

 
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
  
Example 2:
Input: head = [1], n = 1
Output: []
  
Example 3:
Input: head = [1,2], n = 1
Output: [1]


#APPROACH:-
-CALCULATE TOTAL LENGTH OF THE LIST, AND TRACK THE NTH NODE TO BE DELETED FROM THE BEGINNING OF THE LSI.
-EDGE CASE: IF (N == LENGTH), MEANS THE HEAD OF THE LIST IS TO BE DELETED.
-SO MAKE HEAD->NEXT AS THE NEW HEAD & DELETE OLD HEAD, THEN RETURN THE NEW HEAD.
-NOW MAKE TWO POINTERS P & Q, & ASSIGN THEM HEAD.
-TRAVERSE THE LIST AND POINT Q TO THE NODE TO BE DELETED, AND P TO THE NODE JUST BEFORE IT.
-THEN CHANGE THE LINKS, MAKE P->NEXT = Q->NEXT.
-DELETE Q, RETURN HEAD.

      TIME COMPLEXITY:- O(N)
      SPACE COMPLEXITY:- O(1)                                                                       */


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int length=0;
          while(temp!=nullptr){                 //CALCULATING LENGTH
            length++;
            temp=temp->next;
          }
          if(n==length){                          //EDGE CASE
            ListNode* newHead=head->next;
            delete head;
            return newHead;
          }
          ListNode*p=head;
          ListNode*q=head->next;
          for(int i=1;i<(length-n);i++){
            p=p->next;
            q=q->next;
          }
          p->next=q->next;            //CHANGING LINKS
          delete q;
          return head;
    
    }
};
