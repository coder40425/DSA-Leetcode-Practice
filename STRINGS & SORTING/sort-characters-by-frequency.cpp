/* Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.


Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
  
Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
  
Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


APPROACH-1:
-WE CAN USE A CUSTOM COMPARATOR TO SORT.
-IF (FREQ[A] == FREQ[B]), RETURN A<B (OR A>B). AS IT KEEPS CHARACTER IN LEXICOGRAPHICAL ORDER.
-ELSE, RETURN FREQ[A] > FREQ[B] (HIGHER FREQUENCY COMES FIRST).
  

             TIME:- O(N LOG N) [SORTING]
             SPACE:-O(LOG N)                                                                                      */

                             
  class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(128,0);
        for(auto ch: s){
            freq[ch]++;
        }
        auto cmp=[&](char a, char b){
            if(freq[a]==freq[b]){
                return a<b;
            }
            else{
                return freq[a]>freq[b]; 
                }
        };
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};


/*
APPROACH-2 (OPTIMAL):
-IDEA: INSTEAD OF SORTING CHARACTERS MANUALLY, WE USE A BUCKET WHERE INDEX = FREQUENCY.
-THEREFORE, WE APPEND CHARACTERS FROM HIGH FREQ. TO LOW FREQ.
-SO FIRST OF ALL, COUNT THE FREQUENCY USING A FREQUENCY ARRAY OF SIZE 128.  (STANDARD ASCII HAS 128 VALUES)
-CREATE AN ARRAY BUCKET WHERE BUCKET[i] STORES ALL CHARACTERS THAT APPEAR 'i' TIMES.
-NOW, CREATE A STRING RESULT, THAT WILL STORE THE SORTED ANSWER.
-ITERATE FROM HIGH FREQUENCY TO LOW, SO THAT CHARACTER WITH HIGHER FREQ. GO FIRST.

    TIME COMPLEXITY:- O(N)
    SPACE COMPLEXITY:- O(N)                                                                             */


class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(128,0);                    //STANDARD ASCII HAS 128 VALUES
        for(char ch: s){
            freq[ch]++;
        }
        vector<string>bucket(s.size()+1);
        for(int i=0;i<128;i++){
            if(freq[i]>0){
                bucket[freq[i]]+=string(freq[i],i);
            }
        }
        string result;
        for(int i=bucket.size()-1;i>0;i--){             //ITERATE FROM HIGH FREQ. TO LOW
            if(!bucket[i].empty()){
                result+=bucket[i];
            }
        }
        return result;
    }
};
