class Solution {
public:
    
    bool winnerOfGame(string colors) {
      return solve(colors, 'A') > solve(colors, 'B');  
    }
    
    
    int solve(string &s, char ch){
        int ans = 0;
        for(int i = 1; i < s.size(); i++)
            if(s[i-1] == ch && s[i] && s[i] == ch && s[i+1] == ch) 
                ans++;
        return ans;
    }
 
};