class Solution {
public:
    // int minNumberOfFrogs(string str) {
    //     map<char,int>mp;
    //     int n=str.length();
    //     for(int i=0;i<n;i++){
    //         mp[str[i]]++;
            
    //     }
    //     int x=mp[str[0]];
    //     for(auto it:mp){
    //         if(mp[it.first]!=x)return -1;
    //     }
    //     int val=0,ans=0;
    //     for(int i=0;i<n;i++){
    //         if(str[i]=='c'){
    //             val++;
    //         }
    //         else if(str[i]=='k'){
    //             val--;
    //         }
    //         ans=max(ans,val);
    //     }
    //     return ans;
    // }

    int minNumberOfFrogs(string str) {
        int n=str.length();
        int c=0,r=0,o=0,a=0,k=0,cnt=0;
        for(int i=0;i<n;i++){
            if(str[i]=='c'){
                c++;
                cnt=max(cnt,c-k);
            }
            else if(str[i]=='r'){
                r++;
            }
            else if(str[i]=='o')o++;
            else if(str[i]=='a')a++;
            else if(str[i]=='k')k++;
            if(c<r||r<o||o<a||a<k)return -1;
            else continue;
        }
        return (c==r && r==o && o==a && a==k)?cnt:-1;
    }
};