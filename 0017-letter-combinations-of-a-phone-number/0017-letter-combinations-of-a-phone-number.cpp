class Solution {
public:
    vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backT(int idx,string dig,vector<string>&ans,string& curr){
        if(curr.size()==dig.size()){
            ans.push_back(curr);return;
        }
        int di=dig[idx]-'0';
        string &let=mp[di];
        for(char ch:let){
            curr.push_back(ch);
            backT(idx+1,dig,ans,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;string curr="";
        backT(0,digits,ans,curr);
        return ans;
    }
};