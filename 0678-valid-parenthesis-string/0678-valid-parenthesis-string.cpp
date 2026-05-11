class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        int n=s.size();
        //low: minimum possible opens
        //high: maximum possible opens
        for(int i=0;i<n;i++){
            if(s[i]=='(')low++,high++;
            else if(s[i]==')')low--,high--;
            else low--,high++;
            //we can never run out op opens
            if(low<0)low=0;
            //insufficient opens
            if(high<0)return false;
        }
        return low==0;

    }
};