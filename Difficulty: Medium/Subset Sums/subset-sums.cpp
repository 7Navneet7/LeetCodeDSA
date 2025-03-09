//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void subset(int ind,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
        int n=arr.size();
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[ind]);
        subset(ind+1,arr,ds,ans);
        ds.pop_back();
        subset(ind+1,arr,ds,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        // vector<vector<int>>ans;
        // for(int i=0;i<arr.size();i++){
        //     vector<int>brr={0};brr.push_back(arr[i]);
        //     ans.push_back(brr);
        //     for(int j=i+1;j<arr.size();j++){
        //         brr.push_back(arr[j]);
        //         ans.push_back(brr);
        //     }
        // }
        // vector<int>total;
        // for(int i=0;i<ans.size();i++){
        //     int sum=0;
        //     for(int j=0;j<ans[i].size();j++){
        //         sum+=ans[i][j];
        //     }
        //     total.push_back(sum);
        // }
        // total.push_back({0});
        // sort(total.begin(),total.end());
        // return total;
        int n=arr.size();
        vector<vector<int>>ans;
        vector<int>ds;
        subset(0,arr,ds,ans);
        vector<int>total;
        for(int i=0;i<ans.size();i++){
            int sum=0;
            for(int j=0;j<ans[i].size();j++){
                sum+=ans[i][j];
            }
            total.push_back(sum);
        }
        sort(total.begin(),total.end());
        return total;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends