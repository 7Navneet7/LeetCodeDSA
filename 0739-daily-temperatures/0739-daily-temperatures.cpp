class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n=temps.size();stack<int>st;
        //st.push(temps[0]);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++ ){
            while(!st.empty() && temps[st.top()]<temps[i]){
                int d=i-st.top();
                ans[st.top()]=d;
                //st.pop();
                st.pop();
            }
            st.push(i);
        }
        return ans;
        
    }
};