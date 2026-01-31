class Solution {
public:
    string reverseByType(string s) {
        string t1="",t2="";
        int n=s.size();map<int,char>mp1,mp2;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                t1+=s[i];mp1[i]=s[i];
            }
            else{
                t2+=s[i];mp2[i]=s[i];
            }
        }
        reverse(t1.begin(),t1.end());reverse(t2.begin(),t2.end());
        int i=0,j=0;
        for(auto[k,v]:mp1){
            s[k]=t1[i];i++;
        }
        for(auto[k,v]:mp2){
            s[k]=t2[j];j++;
        }
        return s;
    }
};