//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        // code here
        vector<int>arr;
        a=a+1;
        b=b+2;
        arr.push_back(a);
        arr.push_back(b);
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        Solution obj;
        vector<int> ans = obj.passedBy(a, b);
        cout << ans[0] << " " << ans[1] << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends