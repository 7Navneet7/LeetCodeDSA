class Solution {
public:
    bool isPalindrome(string &s,int st,int en){
        while(st<=en){
            if(s[st++]!=s[en--])return false;
        }
        return true;
    }
    void partHelper(int ind,string &s,vector<string>&path,vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(path);return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                partHelper(i+1,s,path,ans);
                path.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;vector<vector<string>>ans;
        partHelper(0,s,path,ans);
        return ans;
    }
};