class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        
        vector<int>ans(0);
        sort(sums.begin(), sums.end());
        for(int i=0; i<n; i++) {
            unordered_map<int, int>mp;
            int d = sums[1] - sums[0];
            vector<int>v1, v2;
            bool flag=false;
            for(int k=0; k<sums.size(); k++) {
                if(!mp[sums[k]]) {
                    v1.push_back(sums[k]);
                    mp[sums[k]+d]++;
                    if(sums[k]==0)
                        flag=true;
                }
                else {
                    v2.push_back(sums[k]);
                    mp[sums[k]]--;
                }
            }
            if(flag) {
                ans.push_back(d); 
                sums = v1; 
            }
            else {
                ans.push_back(-d); 
                sums = v2; 
            }
        }
        return ans;
    }
};