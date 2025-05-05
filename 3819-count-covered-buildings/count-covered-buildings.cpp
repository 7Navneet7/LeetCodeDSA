class Solution {
public:
    // int countCoveredBuildings(int n, vector<vector<int>>& builds) {
    //     int n1=builds.size(),m=builds[0].size();
    //     int cnt=0;
    //     for(int i=0;i<n1;i++){
    //         int l=0,r=0,t=0,b=0;
    //         for(int j=0;j<n1;j++){
    //             if(builds[i][0]==builds[j][0] && builds[i][1]<builds[j][1])t++;
    //             if(builds[i][0]==builds[j][0] && builds[i][1]>builds[j][1])b++;
    //             if(builds[i][1]==builds[j][1] && builds[i][0]>builds[j][0])l++;
    //             if(builds[i][1]==builds[j][1] && builds[i][0]<builds[j][0])r++;

    //         }
    //         if(l>=1 && r>=1 && t>=1 && b>=1)cnt++;
    //     }
    //     return cnt;
    // }



    int countCoveredBuildings(int n, vector<vector<int>>& builds){
        int cnt=0;
        unordered_map<int,set<int>>mp1,mp2;
        for(auto &p: builds){
            mp1[p[0]].insert(p[1]);
            mp2[p[1]].insert(p[0]);
        }
        for(auto &p:builds){
            auto& it1=mp1[p[0]];
            auto& it2=mp2[p[1]];
            auto [lowY,highY]=it1.equal_range(p[1]);
            auto [lowX,highX]=it2.equal_range(p[0]);
            bool up=highY!=it1.end();
            bool down=lowY!=it1.begin();
            bool left=lowX!=it2.begin();
            bool right=highX!=it2.end();
            if(left && right && up && down)cnt++;

        }
        return cnt;
    }
};