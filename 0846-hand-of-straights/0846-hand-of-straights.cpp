class Solution {
public:
    bool isNStraightHand(vector<int>& hd, int gs) {
        int hl=hd.size();
        if(hl%gs!=0)return 0;
        //frquency mapping
        map<int,int>mp;
        for(auto &it:hd){
            mp[it]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            //inherent order constraint
            int cc=it->first;
            int ccf=it->second;
            //check the quantity of rest consecutive cards
            if(ccf>0){
            for(int i=0;i<gs;i++){
                int nc=cc+i;
                if(mp[nc]<ccf)return 0;
                mp[nc]-=ccf;
            }
            }
        }
        return 1;
    }
};