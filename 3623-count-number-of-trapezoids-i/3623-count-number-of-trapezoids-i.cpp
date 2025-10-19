class Solution {
public:
    using ll=long long;
    int countTrapezoids(vector<vector<int>>& points) {
        // int n=points.size();int cnt=0;int neg=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n&&i!=j;j++){
        //         if(i!=j && points[i][1]==points[j][1]){
        //             cnt++;

        //     }
        // }
        // return cnt*(cnt-1)/2;

        //storing the number of points of same height with its height as key
        unordered_map<ll,ll>mp; ll lines=0;ll ans=0;ll mod=1e9 +7;
        for(auto it:points){
            mp[it[1]]++;
        }
        //we need 2 points to make a line, total lines possible are:
        for(auto &it:mp){
            ll shPoints=it.second;
            ll shLines=shPoints*(shPoints-1)/2;
            lines+=shLines;
        }
        //we can only pair the points at different heights for parallel sides
        for(auto &it:mp){
            ll shLines=it.second*(it.second-1)/2;
            //we can't pair the same height lines among them
            //we will make 2 groups. one group of same height lines and another group of 
            //total lines not containing these same height lines
            lines-=shLines;
            ans+=(lines)*shLines;
        }
        return ans%mod;
    }
};