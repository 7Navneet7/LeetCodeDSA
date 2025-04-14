class Solution {
public:
    // long long candy(vector<int>& rats) {
    //     long long n=rats.size();sort(rats.begin(),rats.end());
    //     long long c=0, k=1, i=0;
    //     while(i<n-1){
    //         c+=k;
    //         while(rats[i]==rats[i+1]&&i<n-1){
    //             c+=k;i++;
    //         }
    //         k++;
    //     }
    //     return c;
        
    // }

    int candy(vector<int>&rats){
        int n=rats.size();
        vector<int>cand(n,1);
        for(int i=1;i<n;i++){
            if(rats[i]>rats[i-1])cand[i]=cand[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(rats[i]>rats[i+1]){
                cand[i]=max(cand[i],1+cand[i+1]);
                //cand[i]=1+cand[i+1];
            }
        }
        int tot=0;
        for(int x:cand)tot+=x;
        return tot;
    }
};