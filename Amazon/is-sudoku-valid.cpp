// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        unordered_map<int, unordered_set<int>> row, column, grid;

        int n=mat.size(), m= mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(mat[i][j]){
                    int val=mat[i][j];
                    if(row[i].count(val)) return false;

                    if(column[j].count(val)) return false;

    
                    int box= (i/3)*3+j/3;
                    if(grid[box].count(val)) return false;

                
                    row[i].insert(val);
                    column[j].insert(val);
                    grid[box].insert(val);
                }
            }
        }

        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends