class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        map<char,int>mp;
        for(char ch:t)mp[ch]++;
        int charRem=t.size();
        int minWind[2]={0,INT_MAX};
        int stInd=0;
        for(int enInd=0;enInd<s.size();enInd++){
            char ch=s[enInd];
            if(mp.find(ch)!=mp.end()&& mp[ch]>0){
                charRem--;
            }
            mp[ch]--;
            if(charRem==0 ){
                while(true){
                    char chAtSt=s[stInd];
                    if(mp.find(chAtSt)!=mp.end()&& mp[chAtSt]==0)break;
                    mp[chAtSt]++;
                    stInd++;
                }
                if(enInd-stInd<minWind[1]-minWind[0]){
                    minWind[1]=enInd;minWind[0]=stInd;
                }
                mp[s[stInd]]++;
                charRem++;stInd++;
            }
        }
        return minWind[1]>=s.size()?"":s.substr(minWind[0],minWind[1]-minWind[0]+1);
        
    }
};