class Solution {
public:
    
    int dp[201][201];
    int getMoneyAmount(int n){
        
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
    
    int solve(int lo, int hi) {
        if(hi <= lo) return 0;        
        if(dp[lo][hi] != -1) return dp[lo][hi];
        
        int ans = INT_MAX;
        
        for(int i = lo; i <= hi; i++){
            ans = min(ans, i + max(solve(lo,i-1),solve(i+1,hi)));
        }
        return dp[lo][hi] = ans;
    }
    
};