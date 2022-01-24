// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int minRow = 0;
        int maxRow = r - 1;
        int minCol = 0;
        int maxCol = c - 1;
        int totalEle = r*c;
        int count = 0; 
    
        vector<int> ans;
        while(count < totalEle){
        
            //top wall
            for(int i = minRow, j = minCol; j <= maxCol && count < totalEle; j++){
                ans.push_back(matrix[i][j]);
                count++;
            }
            minRow++;
            
            
            //right wall
            for(int i = minRow, j = maxCol; i <= maxRow && count < totalEle; i++){
                ans.push_back(matrix[i][j]);
                count++;
            }
            maxCol--;
            
            
            //bottom wall
            for(int i = maxRow, j = maxCol; j >= minCol && count < totalEle; j--){
                ans.push_back(matrix[i][j]);
                count++;
            }
            maxRow--;
            
            
            //left wall
            for(int i = maxRow, j = minCol; i >= minRow && count < totalEle; i--){
                ans.push_back(matrix[i][j]);
                count++;
            }
            minCol++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends