/* You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
  
Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
  
Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]


#APPROACH:-
-Create two empty stacks s1, s2.
-Push all nodes from l1 into s1.
-Push all nodes from l2 into s2.
-Initialize carry = 0 and result = nullptr.
-While s1 or s2 not empty or carry not zero:
-Pop top from s1 and s2 if available, else use 0.
-Calculate sum = popped values + carry.
-Create new node with value sum % 10.
-Set new node’s next to result.
-Update result to new node.
-Update carry = sum / 10.
-Return result.


    TIME COMPLEXITY- O(N + M + max(N,M))   // N-> LENGTH OF L1, M-> LENGTH OF L2.
    SPACE COMPLEXITY- O(N + M)      //TWO STACKS USED OF SIZE N & M.
                                                                                                                  */

class Solution {
public:
     stack<int>s1,s2;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ptr1=l1;
        ListNode*ptr2=l2;
        while(ptr1!=nullptr){
            s1.push(ptr1->val);            //PUSING VALUESIN S1
            ptr1=ptr1->next;
        }
        while(ptr2!=nullptr){
            s2.push(ptr2->val);            //PUSHING VALUES IN S2
            ptr2=ptr2->next;
        }
       ListNode*head=nullptr;
       int carry=0;
       while(!s1.empty() || !s2.empty() || carry!=0){
        int sum=0;
        if(!s1.empty()){
            sum=sum+s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            sum=sum+s2.top();
            s2.pop();
        }
        sum=sum+carry;
        carry=sum/10;
        ListNode* newNode= new ListNode(sum%10);
        newNode->next= head;
        head= newNode;

       }
       return head;
    }
};
 
