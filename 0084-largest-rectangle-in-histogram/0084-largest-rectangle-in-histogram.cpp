class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {
        int n=hts.size();stack<int>st;
        hts.push_back(0);
        int mxa=0;
        // for(int i=0;i<hts.size();i++){
        //     int l,r;
        //     if(st.empty()||hts[st.top()]<=hts[i]){
        //         st.push(i);
        //         continue;
        //     }
        //      while(hts[st.top()]>hts[i]){
        //         r=i;
        //         int k=st.top();
        //         st.pop();
        //         if(st.empty())l=k;
        //         else l=st.top();
        //         mxa=max(mxa,(r-l-1)*hts[k]);
        //     }
        // }
        // return mxa;
        for(int i=0;i<hts.size();i++){
            // finding leeft and right range for st.top()
            while(!st.empty()&& hts[st.top()]>hts[i]){
                int k=st.top();
                int r=i;
                st.pop();
                int l=(st.empty()?-1:st.top());
                mxa=max(mxa,(r-l-1)*hts[k]);
            }
            st.push(i);
        }
        return mxa;
        
    }
};