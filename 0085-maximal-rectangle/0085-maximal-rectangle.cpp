class Solution {
public:
    int maxAr(vector<int>hts){
        stack<int>st;
        hts.push_back(0);
        int mxa=0;
        for(int i=0;i<hts.size();i++){
            while(!st.empty() && hts[st.top()]>hts[i]){
                int k=st.top();
                st.pop();
                int r=i;
                int l=(st.empty()?-1:st.top());
                mxa=max(mxa,(r-l-1)*hts[k]);
            }
            st.push(i);
        }
        return mxa;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int rs=mat.size();int cs=mat[0].size();
        vector<int>hts(cs,0);
        int mxa=0;
        for(int i=0;i<rs;i++){
            for(int j=0;j<cs;j++){
                if(mat[i][j]=='1')hts[j]++;
                else hts[j]=0;
            }
            mxa=max(mxa,maxAr(hts));
        }
        return mxa;

    }
};