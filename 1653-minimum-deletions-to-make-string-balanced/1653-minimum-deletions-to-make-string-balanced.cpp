class Solution {
public:
    int minimumDeletions(string s) {
        int bc=0;int ans=0;
        for(char ch:s){
            if(ch=='b')bc++;
            else if(bc){
                bc--;
                ans++;
            }
        }
        return ans;
    }
};