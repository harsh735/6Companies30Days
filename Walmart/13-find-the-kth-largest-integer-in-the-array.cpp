class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        map<int,vector<string>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i].size()].push_back(nums[i]);
        }
        
        k=nums.size()-k+1;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second.size()>=k){
                vector<string> v1=it->second;
                sort(v1.begin(),v1.end());
                return v1[k-1];
            }
            else{
                k-=it->second.size();
            }
        }
        return "";
    }
};