class Solution {
public:
    // bool partitionArray(vector<int>& nums, int k) {
    //     int n=nums.size();int k1=k;
    //     if(n%k!=0)return false;
    //     map<int,int>mp,mp1;
    //     for(auto &it:nums)mp1[it]++;
    //     vector<pair<int,int>>vec(mp1.begin(),mp1.end());
    //     sort(vec.begin(),vec.end(),[](auto &a,auto &b){
    //         return a.second>b.second;
    //     });
    //     // for(auto &ka:vec){
    //     //     mp[ka.first]=ka.second;
    //     // }
    //     while(n>0){
    //         //while(k1>0){
    //             int k2=0;
    //             for(auto &ka:vec){
    //                 if(k2==k)break;
    //                 if(n<0)return false;
    //                 if(ka.second>0){ka.second--;k2++;n--;}
    //             }
    //             if(k2!=k && n>0)return false;
    //         //}
    //     }
    //     return true;
    // }


    bool partitionArray(vector<int>& nums, int k){
        int n=nums.size();
        if(n%k!=0)return false;
        map<int,int>mp;
        for(auto &it:nums)mp[it]++;
        int grp=n/k;
        for(auto &[key,val]:mp){
            if(val>grp)return false;
        }
        return true;
    }
};