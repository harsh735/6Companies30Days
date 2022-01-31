class Solution {
public:
        
    int dp[501][501];
    bool stoneGame(vector<int>& piles) {
        
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int i : piles)sum += i;
        
        int alice = solve(piles,0,piles.size()-1);
        if(2*alice > sum) return true;
        return false;
    }
    
    int solve(vector<int>& piles,int i,int j){
        if(i > j) return 0;
        if(i == j) return dp[i][j] = piles[i];
        if(dp[i][j] != -1) return -1;
        
        int l = piles[i]+solve(piles,i+1,j);
        int r = piles[j]+solve(piles,i,j-1);
        return dp[i][j] = max(l,r);
    }
    
};