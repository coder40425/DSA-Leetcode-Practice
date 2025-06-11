/* Given a linked list, swap every two adjacent nodes and return its head. 
  You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 
Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]



#APPROACH:-
-INITIALIZE A POINTER CURR TO HEAD AND PREV TO NULL.
-TRAVERSE THE LIST IN PAIRS. FOR EACH PAIR OF NODES, SWAP THEIR LINKS.
-UPDATE PREV TO POINT TO THE SECOND NODE AFTER SWAP, AND MOVE CURR TWO NODES AHEAD.
-HANDLE HEAD SEPARATELY AS THE FIRST SWAP CHANGES HEAD.
-CONTINUE UNTIL END OF LIST OR LESS THAN TWO NODES REMAIN.

             TIME COMPLEXITY: O(N)
             SPACE COMPLEXITY: O(1)                                                              */


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){        //EDGE CASE
            return head;
        }
        ListNode*curr=head;
        ListNode*prev=nullptr;
        ListNode*newHead=head->next;
        while(curr!=nullptr && curr->next!=nullptr){
            ListNode*first=curr;
            ListNode*second=curr->next;
            ListNode*nextpair=second->next;
            second->next=first;
            first->next=nextpair;
            if(prev!=nullptr){
                prev->next=second;
            }
            prev=first;
            curr=nextpair;
        }
        return newHead;
    }
};
