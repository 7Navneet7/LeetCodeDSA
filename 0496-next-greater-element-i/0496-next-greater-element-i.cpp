class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& ar, vector<int>& br) {
        int bl=br.size();
        vector<int>rt(bl,-1);
        stack<int>st;
        for(int i=bl-1;i>=0;i--){
            while(!st.empty()&& st.top()<=br[i]){
                st.pop();
            }
            if(!st.empty()){
                rt[i]=st.top();
            }
            st.push(br[i]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<bl;i++){
            mp[br[i]]=i;
        }
        int al=ar.size();
        vector<int>rs(al);
        for(int i=0;i<al;i++){
            int id=mp[ar[i]];
            rs[i]=rt[id];
        }
        return rs;
    }
};