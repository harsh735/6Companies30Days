// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    int memo[1001][1001];
    int mod = 1e9+7;
    int numOfWays(int n, int x)
    {
        // code here
        memset(memo,-1,sizeof(memo));
        return solve(n,x,1);
    }
    int solve(int sum,int x, int base){
        
        int result = pow(base, x);
       
        if(sum == 0) return 1;
        if(sum < result) return 0;

        if(memo[sum][base] != -1) return memo[sum][base];
        
        int consider = solve(sum - result, x, base + 1);
        int notConsider = solve(sum, x, base+1);
        
        return memo[sum][base] = (consider + notConsider)%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends