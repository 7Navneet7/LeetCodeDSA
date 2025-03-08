//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n=text.length();
        int m=pat.length();
        for(int i=0;i<n-m+1;i++){
            bool f=true;
            for(int j=0;j<m;j++){
                if(text[i+j]!=pat[j]){
                    f=false;
                }
            }
            if(f){
                return i;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends