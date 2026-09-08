class Solution {
public:
    int candy(vector<int>& rats) {
        int n=rats.size();
        vector<int>a(n,1);
        //greedy 2 pass
        for(int i=1;i<n;i++){
            if(rats[i]>rats[i-1]){
                a[i]=a[i-1]+1;
            }
        }        
        for(int i=n-2;i>=0;i--){
            if(rats[i]>rats[i+1]){
                a[i]=max(a[i],a[i+1]+1);
            }
        }
        return accumulate(a.begin(),a.end(),0);
    }
};