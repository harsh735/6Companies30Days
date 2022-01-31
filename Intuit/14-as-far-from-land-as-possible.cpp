class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j]==1){
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int k = 0; k<size;k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i >= 0 && j >= 0 && i<row && j<col && grid[i][j]==0){
                    grid[i][j] = ans;
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        return ans == 1 ? -1 : ans-1;
    }
};