class Solution {
public:
     
    void dfs(vector<vector<int>>& heights, int i, int j, int prev,vector<vector<bool>>& ocean){
        
        if(i< 0 || j< 0 || i > heights.size() - 1 || j > heights[0].size() - 1 || ocean[i][j]) return;
        if(heights[i][j] < prev) return; 
        
        ocean[i][j] = true;
        
        dfs(heights,i + 1,j,heights[i][j],ocean);
        dfs(heights,i - 1,j,heights[i][j],ocean);
        dfs(heights,i,j + 1,heights[i][j],ocean);
        dfs(heights,i,j - 1,heights[i][j],ocean);
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    
        vector<vector<int>> ans;
        
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<bool>> pacific(row,vector<bool>(col,false));
        vector<vector<bool>> atlantic(row,vector<bool>(col,false));
        
        
        for(int i = 0; i<col; i++){
            dfs(heights,0,i,INT_MIN,pacific);
            dfs(heights,row - 1,i,INT_MIN,atlantic);
        }
        
        for(int i = 0; i<row; i++){
            dfs(heights,i,0,INT_MIN,pacific);
            dfs(heights,i,col - 1,INT_MIN,atlantic);
        }
        
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    vector<int> v{i,j};
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};