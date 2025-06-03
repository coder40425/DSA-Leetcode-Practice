/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]             


APPROACH:-
-INITIALIZE TWO POINTERS K = 0 AND I = 0.
-TRAVERSE THE ARRAY USING I FROM 0 TO N - 1.
-IF NUMS[K] == 0 & NUMS[I] != 0, SWAP NUMS[K] AND NUMS[I].
-INCREMENT K AFTER EACH VALID SWAP TO TRACK THE NEXT POSITION FOR NON-ZERO ELEMENT.
-AT THE END, ALL NON-ZERO ELEMENTS WILL BE AT THE FRONT AND ZEROES PUSHED TO THE BACK.


             TIME COMPLEXITY :- O(N)
             SPACE COMPLEXITY:- O(1)                                                                            */


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==0 && nums[k]!=0){            
            k=i;                          //TO MAKE 'K' POINT TO ALL THE ZEROES AS 'I' TRAVERSE THROUGH THE ARRAY
        }
        if(nums[k]==0 && nums[i]!=0){
            nums[k]=nums[i];                       //SWAPPING NUMS[I] & NUMS[K]
            nums[i]=0;
            k++;
        }
     }
    }
};
 
