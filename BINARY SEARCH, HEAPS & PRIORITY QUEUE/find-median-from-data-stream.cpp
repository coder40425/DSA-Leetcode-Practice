/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, 
 and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]                 */

/*
##APPROACH:-
-Two heaps
-Max Heap - Left half of numbers(smaller values), Min Heap- Right half of numbers(larger values)
-Size of max heap is always equal to or 1 greater than min heap.
-If no. total elements odd -> median is the top of max heap
-If no. total elements even -> median is average of tops of both heaps.

      TIME COMPLEXITY:-O(log n)      SPACE COMPLEXITY:-O(n)           */

class MedianFinder {
public:
  priority_queue<int> left; //to store the smaller left half
  priority_queue<int, vector<int>, greater<int>>right; //to store the larger right half

    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        else{
            return (left.top() + right.top())/2.0;
        }
    }
};

