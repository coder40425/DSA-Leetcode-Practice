/*Given two strings s and t, determine if they are isomorphic.
 Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 All occurrences of a character must be replaced with another character while preserving the order of characters. 
 No two characters may map to the same character, but a character may map to itself.


Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation: The strings s and t can be made identical by:
              Mapping 'e' to 'a'.
              Mapping 'g' to 'd'.                                   */

/*
##APPROACH 1:-
-Using unordered maps (bi-directional mapping)
-Use two hashmaps: one from s -> t, one from t -> s
-While traversing, check if existing mapping violates one-to-one condition.

       TIME COMPLEXITY:- O(N)    SPACE COMPLEXITY:- O(N)               */

//MY SOLUTION
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //edge case
        if(s.size() != t.size()) return false;
        unordered_map<char,char> map_s_t; //to map s to t
        unordered_map<char,char> map_t_s; //to map t to s

        for(int i=0;i<s.size();i++){
             //if s[i] already mapprd, check if it matches t[i]
             if(map_s_t.count(s[i]) && map_s_t[s[i]] != t[i]) return false;
             //if t[i] already mapped, check if it matches s[i]
             if(map_t_s.count(t[i]) && map_t_s[t[i]] != s[i]) return false;

             //new mapping
             map_s_t[s[i]] = t[i];
             map_t_s[t[i]] = s[i];
        }
        return true;
    }
};

/*
##APPROACH-2:- (Optimal)
-Use two vectors of size 128 (for ASCII)
-For each character at index i, store the last seen index for s[i] and t[i].
-If last seen indices differ -> not isomorphic.

    TIME COMPLEXITY:- O(N)       SPACE COMPLEXITY:-O(1)              */

//MY SOLUTION
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>v1(128, -1);
        vector<int>v2(128, -1);

        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            //checks if value at index i match both vectors
            if(v1[s[i]]!=v2[t[i]]){  
              return false;
            } 
            //storing string position in vectors for characters at index i
            v1[s[i]] = v2[t[i]] = i; 
        }
        return true;
    }
};
