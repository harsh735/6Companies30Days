class Solution {
public:
    
    bool isPossible(vector<int>&piles,int h, int mid){
        
        int time = 0;
        for(int i = 0; i<piles.size(); i++){
            time += ceil(1.0 * piles[i] / mid);
        }
        return time <= h ? true : false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi = 0;
        for(int i = 0; i<piles.size(); i++) {
            maxi = max(maxi,piles[i]);
        }
        
        if(h == piles.size()) 
            return maxi;
        
        int start = 1;
        int end = maxi;
        int ans = 0;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(piles,h,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};