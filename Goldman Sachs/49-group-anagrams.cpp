class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans; 
        unordered_map<string,vector<string>> memo;
        
        for(int i = 0; i<strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(),word.end());
            memo[word].push_back(strs[i]);
        }
        
        for(auto it: memo) 
            ans.push_back(it.second);
        
        return ans;
    }
};