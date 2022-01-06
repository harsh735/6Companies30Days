#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> maxTen(int nums[],int n)
    {
        vector<int> ans(0);
        priority_queue<int> q;
        for(int i=0;i<n;i++)
            q.push(nums[i]);

        for(int i=0;i<k;i++){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};