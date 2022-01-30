// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && dfs(board,i,j,0,word))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>&board, int i, int j, int count,string word){
        
        if(count == word.length()) return true;
        if(i == -1 || j == -1 || i == board.size() || j == board[0].size() || board[i][j] != word[count])
            return false;
            
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board,i + 1,j,count + 1,word) ||
                     dfs(board,i - 1,j,count + 1,word) ||
                     dfs(board,i,j + 1,count + 1,word) ||
                     dfs(board,i,j - 1,count + 1,word);
        board[i][j] = temp;
        return found;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends