class Solution {
public:
    using ll=long long;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,ll>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // init
        vector<ll>dist(n,LLONG_MAX);
        vector<ll>ways(n,0);
        dist[0]=0;ways[0]=1;
        ll mod=1e9+7;

        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto[ct,cn]=pq.top();pq.pop();
            if(ct>dist[cn])continue;
            for(auto&[nein,neit]:adj[cn]){
                ll nt=neit+ct;
                if(nt<dist[nein]){
                    dist[nein]=nt;
                    pq.push({nt,nein});
                    ways[nein]=ways[cn];
                }
                else if(nt==dist[nein]){
                    ways[nein]=(ways[nein]+ways[cn])%mod;
                }
            }
        }
        return ways[n-1];
    }
};