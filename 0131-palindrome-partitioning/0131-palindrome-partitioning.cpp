class Solution {
public:
    bool isPal(string s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r])return 0;
            l++;
            r--;
        }
        return 1;
    }
    void backT(int st,string s,vector<string>&curr,vector<vector<string>>&ans){
        //base case
        if(st==s.size()){
            ans.push_back(curr);
            return;
        }
        //loop based branching
        for(int i=st;i<s.size();i++){
            string sub=s.substr(st,i-st+1);
            if(isPal(s,st,i)){
                curr.push_back(sub);
                backT(i+1,s,curr,ans);
                curr.pop_back();
            }
            else continue;
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        //st denotes the beggining point of current split
        backT(0,s,curr,ans);
        return ans;
    }
};