class Solution {
public:
    
     //application of split array largest sum, ditto copy
     bool isValid(vector<int>& weights, int days, int mid) {
        int sum = 0;
        int d = 1;
         
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if(sum > mid) {
                d++;
                sum = weights[i];
            }
            if(d > days)
                return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxi = 0;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        
        if(weights.size() == days) return maxi;
        
        int start = maxi, end = sum;
        int ans = 0;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(isValid(weights, days, mid) == true) {
                ans = mid;
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }
        return ans;
     }
};