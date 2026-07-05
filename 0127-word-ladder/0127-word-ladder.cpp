class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        unordered_set<string>st(wl.begin(),wl.end());
        queue<pair<string,int>>q;
        q.push({bw,1});
        if(st.find(ew)==st.end())return 0;
        while(!q.empty()){
            auto[w,s]=q.front();q.pop();
            if(w==ew)return s;
            for(int i=0;i<w.size();i++){
                char oc=w[i];
                for(char c='a';c<='z';c++){
                    w[i]=c;
                    if(st.find(w)!=st.end()){
                        q.push({w,s+1});
                        st.erase(w);
                    }
                }
                w[i]=oc;
            }

        }
        return 0;
    }
};