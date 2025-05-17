class Solution {
public:
    // int minDeletion(string s, int k) {
    //     int n=s.size();
    //     map<char,int>mp;
    //     for(char c:s)mp[c]++;
    //     multimap<int,char>Mp;
    //     for(auto pa:mp){
    //         Mp.insert({pa.second,pa.first});
    //     }
    //     int kp=n-k;
    //     int i=0;int ans=0;
    //     while(i<kp){
    //         ans+=Mp[]
    //     }
    // }


    int minDeletion(string s, int k){
        int n=s.length();map<char,int>mp;
        for(char c:s)mp[c]++;
        vector<int>vec;
        for(auto pa:mp)vec.push_back(pa.second);
        sort(vec.begin(),vec.end());
        int d=mp.size()-k;
        int ans=0;
        for(int i=0;i<d;i++)ans+=vec[i];
        return ans;
    }
};