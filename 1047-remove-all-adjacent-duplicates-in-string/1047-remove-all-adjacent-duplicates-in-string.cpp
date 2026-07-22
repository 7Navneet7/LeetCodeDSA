class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char ch:s){
            if(st.empty()||st.top()!=ch){
                st.push(ch);
            }
            else if(ch==st.top()){
                st.pop();
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        //s(st.begin(),st.end());
        reverse(s.begin(),s.end());
        return s;
    }
};