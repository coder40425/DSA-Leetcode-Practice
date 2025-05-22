class Solution {
public:
    bool isValid(string s) {
        stack <char> str;
          for(char ch: s){
            if(ch=='(' || ch=='{' || ch=='['){
                str.push(ch);
            }
            else{
                if (str.empty())
                return false;
                
                char top= str.top();
                if((ch==')' && top!='(')|| (ch=='}' && top!='{')|| (ch==']' && top!='[')){
                return false;
                }
                str.pop();
            }
          }
          return str.empty();
    }
};
