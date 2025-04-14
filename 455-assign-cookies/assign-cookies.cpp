class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());sort(s.begin(),s.end());
        if(s.size()==0)return 0;
        int j=0,c=0;
        // for(int i=0;i<g.size();i++){
        //     if(g[i]<=s[j]){
        //         g[i]=0;c++;
        //     }
        //     if(j<s.size()-1){
        //         j++;
        //     }
        //     else{
        //         break;
        //     }    
        // }



        // vector<int>vis(g.size(),0);
        // for(int i=0;i<g.size();i++){
        //     for(int k=0;k<s.size();k++){
        //         if(g[i]<=s[k]&& vis[i]==0){
        //             c++;s[k]=0;vis[i]=1;
        //         }
        //     }
        // }


        int p=0,q=0,co=0;
        while(p<g.size() && q<s.size()){
            if(g[p]<=s[q]){
                p++;q++;co++;
            }
            else{
                q++;
            }
        }
        //return (p);
        return co;
    }
};