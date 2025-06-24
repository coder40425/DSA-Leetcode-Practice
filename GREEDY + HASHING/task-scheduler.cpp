/*You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task.
  Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
            After completing task A, you must wait two intervals before doing A again. The same applies to task B.
            In the 3rd interval, neither A nor B can be done, so you idle.By the 4th interval, you can do A again as 2 intervals have passed.        */

/*
#APPROACH:-
1. Count frequency of each task using a 26-sized array (A–Z).
2. Find the maximum frequency (say maxFreq = 3)
3. Count how many tasks have this max frequency (say maxCount = 2)
4. Use the formula:
      minTime = max( tasks.length, (maxFreq - 1) * (n + 1) + maxCount )
 [maxFreq = frequency of most frequent tasks.
 maxFreq - 1 = gaps between similar tasks.
 count = no. of tasks with maxFreq.]

#COMPLEXITY:-  Time complexity: O(N)     Space complexity: O(1)             */

//MY SOLUTION   
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        //count frequency of each task
        for(char t: tasks){
            freq[t - 'A']++;
        }
        //find task with maximum frequency
        int maxFreq= *max_element(freq.begin(), freq.end());
        int count=0;
        //count how many tasks have maxFreq
        for(int f: freq){
            if(f == maxFreq) count++;
        }
        //apply formula
        int partCount= (maxFreq - 1) * (n+1) + count;
        
        return max((int)tasks.size(), partCount);

    }
};
