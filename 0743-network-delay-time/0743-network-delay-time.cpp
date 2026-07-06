class Solution {
public:
    int networkDelayTime(vector<vector<int>>&a, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:a){
            adj[it[0]].push_back({it[1],it[2]});

        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[ct,cn]=pq.top();pq.pop();
            if(ct>dist[cn])continue;
            for(auto&[nein,neit]:adj[cn]){
                if(dist[nein]>neit+ct){
                    dist[nein]=neit+ct;
                    pq.push({dist[nein],nein});
                }
            }
        }
        int mt=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            mt=max(mt,dist[i]);
        }
        return mt;
    }
};