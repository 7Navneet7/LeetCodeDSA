class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();unordered_map<int,int>full;
        set<int>dry_days;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                int lake=rains[i];ans[i]=-1;
                if(full.count(lake)){
                    auto it=dry_days.upper_bound(full[lake]);
                    if(it==dry_days.end())return {};
                    ans[*it]=rains[i];
                    dry_days.erase(it);
                }
                full[lake]=i;
            }
            else{
                dry_days.insert(i);
            }
        }
        return ans;
    }
};