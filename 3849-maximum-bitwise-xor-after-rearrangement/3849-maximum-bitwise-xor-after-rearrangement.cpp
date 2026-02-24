class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.size();
        int o=0,z=0;
        for(char ch:t){
            if(ch=='0')z++;
            else o++;
        }
        string ans="";
        for(char ch:s){
            if(ch=='0'){
                if(o>0){
                    ans+='1';o--;
                }
                else{
                    ans+='0';z--;
                }
            }
            else{
                if(z>0){
                    ans+='1';z--;
                }
                else{
                    ans+='0';o--;
                }
            }
        }
        return ans;
    }
};