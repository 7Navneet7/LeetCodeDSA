class Solution {
public:
    void backT(vector<string>&ans,string &curr,int op,int cp,int n){
        //base case when reached the limit length n
        if(op==n && cp==n){
            ans.push_back(curr);
            return;
        }
        //the choices that we can make
        //with constraints
        if(op<n){
            curr+="(";
            backT(ans,curr,op+1,cp,n);
            curr.pop_back();
        }
        if(cp<op){
            curr+=")";
            backT(ans,curr,op,cp+1,n);
            curr.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        backT(ans,curr,0,0,n);
        return ans;
    }
};