class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string st="";int cnt=0;
    
        int c=0;int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')cnt++;
            else cnt--;
            c++;
            if(cnt==0){
                st+=s.substr(j+1,c-2);c=0;j=i+1;
            }
        }
        return st;

    }
};