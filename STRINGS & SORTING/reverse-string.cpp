/*  Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
  
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

APPROACH:-
-WE HAVE TO REVERSE THE STRING, THE APPROACH WILL BE TO TRAVERSE AND SWAP.
-AS WHEN WE SEE, WE REALISE WE HAVE TO SWAP THE CHARACTERS OF ( i )TH INDEX AND (n - i - 1)TH INDEX.
-AND WE HAVE TO DO IT TILL THE POINTER REACHES (n / 2)TH INDEX, BECAUSE TILL THEN EVERY CHARACTER WILL BE SWAPPED.
    **WE CAN ALSO DO IT BY USING TWO POINTERS, (LEFT = 0 AND RIGHT = n - 1), THEN SWAP S[LEFT] WITH S[RIGHT] UNTIL (LEFT<RIGHT), 
      BY INCREASING LEFT (LEFT++) AND DECREASING RIGHT (RIGHT--) AFTER EACH ITERATION.

FOR BOTH THE APPROACHES:-
      TIME COMPLEXITY- O(N)
      SPACE COMPLEXITY- O(1)                                                          */
  

//1ST METHOD
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
        }
    }
};

//USING TWO POINTERS
class Solution {
public:
    void reverseString(vector<char>& s) {
       int n=s.size();
       int left=0;
       int right=n-1;
      while(left<right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
};
