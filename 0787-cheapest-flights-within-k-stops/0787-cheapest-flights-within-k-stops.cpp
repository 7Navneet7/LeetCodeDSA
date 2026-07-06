class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int s, int d, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:a){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[s]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{s,0}});
        while(!q.empty()){
            auto[sts,nda]=q.front();q.pop();
            int cn=nda.first;int cc=nda.second;
            if(sts>k)continue;
            for(auto &neida:adj[cn]){
                int nei=neida.first;
                int pri=neida.second;
                if(cc+pri<dist[nei]){
                    dist[nei]=cc+pri;
                    q.push({sts+1,{nei,dist[nei]}});
                }
            }
        }
        return dist[d]==1e9?-1:dist[d];
    }
};