/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation: All elements are distinct.     */

/*
##APPROACH:-
-Use an unordered set to store seen elements.
-While traversing the array:
-If an element already exists in the set, return true.
-Else insert it into the set.
-If loop finishes, return false.

    TIME COMPLEXITY:- O(N)      SPACE COMPLEXITY:- O(N)                     */
                      
//MY SOLUTION
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num: nums){
            if(seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};

/*
##ONE LINER SOLUTION:-
-Insert all elements of nums into an unordered_set (removes duplicates automatically).
-If size of the set is smaller than nums.size(), that means duplicates existed.
-Return true if duplicate found, else false.                                         */

//MY SOLUTION
class Solution {
public:
bool containsDuplicate(vector<int>& nums) {
    return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
}
};
