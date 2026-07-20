class Solution {
public:
    void backT(int n,string &curr,vector<string>&ans){
        //base case
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        //conditional adding of '0'
        if(curr.empty()||curr.back()=='1'){
            curr+='0';
            backT(n,curr,ans);
            curr.pop_back();
        }
        // always adding of '1'
        curr+='1';
        backT(n,curr,ans);
        curr.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
            string curr="";
        backT(n,curr,ans);
        return ans;
    }

};