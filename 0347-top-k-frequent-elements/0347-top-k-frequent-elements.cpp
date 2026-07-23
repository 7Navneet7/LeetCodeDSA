class Solution {
public:

    vector<int> topKFrequent(vector<int>& nu, int k) {
        //int n=nu.size();
        unordered_map<int,int>mp;
        for(auto &it:nu)mp[it]++;
        // vector<pair<int,int>>vec;
        // for(auto&[k,v]:mp){
        //     vec.push_back({k,v});
        // }
        // sort(vec.begin(),vec.end(),[&](auto &a,auto &b){
        //     return a.second>b.second;
        // });
        // int i=0;
        vector<int>ans;
        // while(k--){
        //     ans.push_back(vec[i++].first);
        // }

        priority_queue<pair<int,int>,vector<pair<int,int>>,
        decltype([](auto &a,auto &b){
            return a.second<b.second;
        })>pq;
        for(auto&[ke,v]:mp){
            pq.push({ke,v});
        }
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};