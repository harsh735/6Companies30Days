// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> memo(N + 1, vector<vector<int>>(2, vector<int>(K + 1,-1)));
        return solve(A,0,1,K,memo,N);
    }
    
    int solve(int A[], int currIdx, int canBuy, int transactionCount, vector<vector<vector<int>>>&memo,int N) {
        
        if(currIdx >= N || transactionCount <= 0) return 0;
        
        if(memo[currIdx][canBuy][transactionCount] != -1) return memo[currIdx][canBuy][transactionCount];
                
        
        int idle = solve(A,currIdx + 1,canBuy,transactionCount,memo,N);        
        if(canBuy) {
            int buy = -A[currIdx] + solve(A,currIdx + 1,0,transactionCount,memo,N);
            return memo[currIdx][canBuy][transactionCount] = max(idle,buy);
        } 
        
        else {
            int sell = A[currIdx] + solve(A,currIdx + 1,1, transactionCount - 1,memo,N);
            return memo[currIdx][canBuy][transactionCount] = max(idle,sell);
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends