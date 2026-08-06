class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();

        //find the longest sorted prefix [0,...,l]

        int l=0;
        /*
        while( l<n && arr[l-1]<=arr[l] ){l++;}
        */
        while(l+1<n and arr[l]<=arr[l+1])l++;

        //find the longest sorted suffix [r,...,n-1]

        int r=n-1;
        /*
        while(r-1>=0 && arr[r-1]<=arr[r]){r--;}
        r=min(r+1,n-1); 
        */

        while(r>0 && arr[r-1]<=arr[r])r--;  

        //longest sorted prefix array overlaps with longest sorted suffix array
        //whole array is good to go so 0 ops needed {1,2,3,3,5,6}

        if(l>=r)return 0;    

        //min ops required

        int mops=INT_MAX;

        //1.remove the remaing array after longest sorted prefix i.e[l+1,...,n-1]

        mops=min(mops,n-1-l);

        //2.remove the remaing array before longest sorted suffix i.e[0,...,r-1]

        mops=min(mops,r);

        //3.merge a valid portion from prefix [0,...i] with a valid portion from 
        //suffix [j,...,n-1] and  0<=i<=l and r<=j<=n-1

        for(int i=0;i<=l;i++){
            int j=r;
            while(j<n and arr[i]>arr[j]){
                j++;
            }

            //each time after above while loop we will get
            //[0,...,i] + [j,...,n-1] as a valid sequence
            //so we need to remove inbetween elements [i+1,...,j-1]

            if(j<=n-1)mops=min(mops,j-i-1);
        }
        return mops;
        
    }
};