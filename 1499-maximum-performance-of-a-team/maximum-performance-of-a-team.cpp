class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers;
        for(int i=0;i<n;i++){
            engineers.emplace_back(efficiency[i],speed[i]);

        }
        sort(rbegin(engineers),rend(engineers));
        long speedsum=0,res=0;
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(auto&[e,s]:engineers){
            speedsum+=s;
            min_heap.emplace(s);
            if(min_heap.size()>k){
                speedsum-=min_heap.top();
                min_heap.pop();
            }
            res=max(res,speedsum*e);
        }
        return res%(int)(1e9+7);
    }
};