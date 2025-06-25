class Solution {
public:
        int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> G(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int res = 0;

        function<int(int,int)> dfs = [&](int i, int f) -> long long {
            vector<int> score;
            for (int j : G[i]) {
                if (j == f) continue;
                score.push_back(dfs(j, i));
            }
            if (score.empty()) {
                return cost[i];
            }
            long long ma = *max_element(score.begin(), score.end());
            for (int v : score) {
                if (ma - v > 0) res++;
            }
            return ma + cost[i];
        };

        dfs(0, -1);
        return res;
    }
};