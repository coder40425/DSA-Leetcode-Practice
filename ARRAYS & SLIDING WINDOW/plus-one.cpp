/* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.


Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].     


#APPROACH:-
-MAKE A PONTER RIGHT, AND POINT IT TO THE RIGHTMOST ELEMENT.
-CREATE A LOOP FROM 0 TO N-1
-IF THE RIGHTMOST ELEMENT IS NOT EQUAL TO 9(MEANS IT IS 0,1,2,3,4,.....8), SO ADD 1 TO THE RIGHTMOST ELEMENT & RETURN THE ARRAY.
-IF THE RIGHTMOST ELEMENT IS EQUAL TO 9, MAKE THE RIGHTMOST ELEMENT 0, AND MOVE RIGHT POINTER TO THE LEFT SIDE OF THE LIST(i..e. RIGHT--).
-EDGE CASE: IF ALL ARE 9s, INCREASE THE SIZE OF THE LIST & INSERT 1 AT THE BEGINNING OF THE LIST.

     Time complexity- O(n)
     Space complexity- O(1)                                                                      */ 


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        int right=n-1;
        for(int i=0;i<n;i++){
            if(digits[right]!=9){
              digits[right]+=1;
                return digits;      //if last digit is between 0 to 8 , just add 1 and return outout.
            }
            else{           //digit is 9
                digits[right]=0;
                right--;
            }
        }
        // If loop completes, all digits were 9
        digits.insert(digits.begin(), 1);            //EDGE CASE
        return digits;
    }
};
