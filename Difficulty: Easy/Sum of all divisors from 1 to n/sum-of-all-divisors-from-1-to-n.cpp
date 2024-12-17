//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int sumOfDivisors(int n) {
    //     // Write Your Code here
    //     int s=0;
    //     for(int i=1;i<=n;i++){
    //         int j=1;
    //         while(j<=i){
    //             if(i%j==0){
    //                 s+=j;
    //                 j++;
    //             }
    //             j++;
    //         }
    //     }
    //     return s;
    // }
    
    
    
    vector <int> store;
        for(int i =1; i <= n; i++){
            for(int j = 1; j*j<=i; j++){
                if((i%j) == 0){
                    store.push_back(j);
                    if((i/j)!=j){
                        store.push_back((i/j));
                    }
                }
            }
        }
        int total = 0;
        for(int z: store){
            total += z;
        }
        return total;
    }    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends