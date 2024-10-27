#include<string>
#include<unordered_map>
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        // int no=0;int n=s.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         int c=0;
        //         if(s[i]==s[j]){
        //             c++;
        //         }
        //         if(c==k-1){
        //             no+=n-j;
        //             break;
                        
        //         }
        //     }
        // }
        // return no;
        
        int c=0;int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int>tim;
            for(int j=i;j<n;j++){
                char curr=s[j];
                tim[s[j]]++;
                //bool stat=0;
                for(const auto &itr:tim){
                    if(itr.second>=k){
                        c++;
                        break;
                    }
                }
           }
        }
        return c;
    }
};