class Solution {
public:
    long long totHrs(vector<int>&piles,int k){
        long long hrs=0;
        for(int i=0;i<piles.size();i++)hrs+=((piles[i]+k-1)/k);
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int n=piles.size();
        int l=1,h=*max_element(piles.begin(),piles.end());
        
        while(l<=h){
            int m=(l+h)/2;
            long long hrs=totHrs(piles,m);
            if(hrs<=hr){
                h=m-1;
                
            }
            else{l=m+1;} 
        }
        return l;
    }
};