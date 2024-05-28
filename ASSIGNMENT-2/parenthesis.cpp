class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        int len=s.size();
        if(len%2!=0){
            return false;
        }
        for(int i=0;i<len;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                stck.push(s[i]);
            }
            else if(stck.empty()||(s[i]==')'&&stck.top()!='(')||
                    (s[i]==']'&&stck.top()!='[')||
                    (s[i]=='}'&&stck.top()!='{')){
                      return false;
            }
            else {
                stck.pop();
            }
        }
      return stck.empty();
    }
};