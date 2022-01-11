class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q; 
        int ans = 0;
        int count = 0; 
        int m = grid.size(); //rows 
        int n = grid[0].size(); //columns
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                
                //if orange is rotten
                if(grid[i][j] == 2) q.push({i,j});
                
                //if orange is fresh
                if(grid[i][j] == 1) count += 1;
            }
        }
        
        while(!q.empty()){
            int size = q.size();
            if(count == 0) return ans;
            while(size--){
                auto a = q.front();
                q.pop();
                
                int i = a.first;
                int j = a.second;
                
                
                if(i > 0){
                    if(grid[i - 1][j] == 1){
                        count--;
                        grid[i - 1][j] = 2;
                        q.push({i-1,j});
                    }
                }
                
                
                if(j > 0){
                    if(grid[i][j - 1] == 1){
                        count--;
                        grid[i][j-1] = 2;
                        q.push({i,j-1});
                    }
                }
              
                
                if(i < m - 1){
                    if(grid[i  + 1][j] == 1){
                        count--;
                        grid[i + 1][j] = 2;
                        q.push({i + 1,j});
                    }
                }
                
                  
                if(j < n - 1){
                    if(grid[i][j + 1] == 1){
                        count--;
                        grid[i][j + 1] = 2;
                        q.push({i,j + 1});
                    }
                }
            }
            ans++;
        }
        return count == 0 ? ans : -1;
    }
};