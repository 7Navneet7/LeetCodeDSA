class Solution {
public:
    int reverseDegree(string s) {
        // vector<int>arr(26);
        // for(int i=0;i<26;i++){
        //     arr[i]=26-i;
        // }
        // int ans=0;
        // for(int i=0;i<s.length();i++){
        //     ans+=(i+1)*(arr[int(s[i])-97]);
        // }
        // return ans;

        int deg=0;
        for(int i=0;i<s.length();i++){
            deg+=(26-(s[i]-'a'))*(i+1);
        }
        return deg;
        
    }
};