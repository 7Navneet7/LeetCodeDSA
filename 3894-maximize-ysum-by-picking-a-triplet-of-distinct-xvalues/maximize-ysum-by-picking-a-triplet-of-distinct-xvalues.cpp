class Solution {
public:
    // int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
    //     int n=x.size(),m=y.size();
    //     vector<int>st(x.begin(),x.end());
    //     st.erase(unique(st.begin(),st.end()),st.end());
    //     set<int>st1(x.begin(),x.end());
    //     if(st1.size()<3)return -1;
    //     //vector<int>
    //     int s=st.size();
    //     map<int,vector<int>>mp;
    //     for(int i=0;i<s;i++){
    //         //int ma=0;
    //         for(int j=0;j<n;j++){
    //             if(st[i]==x[j])mp[st[i]].push_back(y[j]);
    //         }
    //     }
    //     vector<int>sum;
    //     for(auto &[key,val]:mp){
    //         sum.push_back(*max_element(val.begin(),val.end()));
    //     }
    //     sort(sum.rbegin(),sum.rend());
    //     int ans=0;
    //     //for(int i=0;i<3;i++)ans+=sum[i];
    //     return sum[0]+sum[1]+sum[2];
    // }

    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y){
        int n=x.size();
        map<int,int>maxY;
        for(int i=0;i<n;i++){
            maxY[x[i]]=max(maxY[x[i]],y[i]);
        }           
        if(maxY.size()<3)return -1;
        vector<int>maxYval;
        for(auto &[k,v]:maxY){
            maxYval.push_back(v);
        } 
        sort(maxYval.rbegin(),maxYval.rend());
        return maxYval[0]+maxYval[1]+maxYval[2];
    }
};