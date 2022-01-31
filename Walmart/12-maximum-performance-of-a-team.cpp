class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> perf(n);
        for(int i=0;i<n;i++) {
            perf[i]={efficiency[i],speed[i]};
        }
        
        sort(rbegin(perf),rend(perf));
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long sum = 0;
        long ans = 0;
        for(auto [eff,speed] : perf){
            sum+=speed;
            pq.push(speed);
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans,sum*eff);
        }
        return ans % (int)(1e9+7);
    }
};