class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();
        unordered_map<int,int>pfq;
        int csm=0;
        int c=0;
        pfq[0]=1;
        for(int i=0;i<n;i++){
            csm+=a[i];
            int pts=csm-k;
            if(pfq.find(pts)!=pfq.end()){
                c+=pfq[pts];
            }
            pfq[csm]++;
        }
        return c;
    }
};