class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int ,double>>> g(n);
        for(int i=0;i<edges.size();i++) {
            g[edges[i][0]].push_back({edges[i][1] , succProb[i]});
            g[edges[i][1]].push_back({edges[i][0] , succProb[i]});
        }
        priority_queue<pair<double,int>> pq; //take maximum of Path prbabilty at the top
        vector<double> prob(n,0.0);
        vector<bool> visited(n,false);
        pq.push({1.0,start});
        while(!pq.empty()) 
        {
            pair<double,int> topnode = pq.top();
            pq.pop();
            double val = topnode.first;
            int node = topnode.second;
            
            if(val > prob[node]) 
            {
                prob[node] = val;   
            }
            visited[node] = true;
            
            for(auto adj : g[node]) {
                if(!visited[adj.first] && prob[adj.first] < prob[node] * adj.second) 
                {
                    pq.push({prob[node] * adj.second , adj.first});
                }
            }
        }        
        return prob[end];
    }
};