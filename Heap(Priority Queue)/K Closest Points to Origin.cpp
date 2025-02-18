//T.C : O(nlogk)
//S.C : O(logk+n)
class Solution {
  public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=points.size();
        
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            int sqred=(x*x) + (y*y);
            int dist=sqrt((sqred));
            pq.push({dist,{x,y}});
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};
