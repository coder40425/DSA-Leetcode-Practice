/*You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. 
 This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
 You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score
 after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 
Example 1:
Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output: [null, 4, 5, 5, 8, 8]                         */

/*
##APPROACH:-
-Using Min-Heap.

  TIME COMPLEXITY:- O(n * log k)     SPACE COMPLEXITY:- O(k)     */

//MY SOLUTION
class KthLargest {
private:
     priority_queue<int, vector<int>, greater<int>> minHeap;  //min heap
     int k;  //to store k value
public:
    KthLargest(int k, vector<int>& nums){
        this->k = k;
        for(int num : nums){
          //push initial elements
            minHeap.push(num);
          //keep only k largest
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    //add a new element to stream
    int add(int val) {
      //push new value to stream
        minHeap.push(val);
        if(minHeap.size() > k){
          //pop smallest, if size > k
            minHeap.pop();
        }
        return minHeap.top();   // top = kth largest
    }
};
