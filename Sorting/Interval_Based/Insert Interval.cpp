//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>>res;
        intervals.insert(intervals.end(),newInterval);
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(end>=intervals[i][0]){
                end=max(end,intervals[i][1]);
            }else{
                res.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        res.push_back({start,end});
        return res;
    }
};
