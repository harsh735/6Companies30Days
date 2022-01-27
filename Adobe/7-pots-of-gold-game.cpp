// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> memo(n + 1,vector<int>(n + 1,-1));
	    return solve(A,n - 1,0,memo);
    }
    
    int solve(vector<int>&A, int n, int currIdx,vector<vector<int>>&memo){
        
        if(currIdx > n) return 0;
        
        if(currIdx == n) return memo[currIdx][n] = A[currIdx];
        if(memo[currIdx][n] != -1) return memo[currIdx][n];
        
        int left = A[currIdx] + min(solve(A,n, currIdx + 2, memo), solve(A,n - 1,currIdx + 1,memo));
        int right = A[n] + min(solve(A, n - 1, currIdx + 1, memo), solve(A,n - 2, currIdx,memo));
        return memo[currIdx][n] = max(left,right);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends