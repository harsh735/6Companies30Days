class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int ans = 0;
                
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j < points.size(); j++) {    
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int key = (dx * dx) + (dy * dy);
                mp[key]++;
            }
        
            for (auto it : mp) {
                if (it.second > 1)
                    ans += it.second * (it.second - 1);
            }
        }
        return ans;
    }
};