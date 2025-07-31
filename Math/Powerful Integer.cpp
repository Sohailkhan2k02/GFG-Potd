class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> start,end;
        
        for(auto it:intervals){
            start.push(it[0]);
            end.push(it[1]);
        }
        
        int ele = -1;
    
        while(!end.empty()){
            while(!start.empty() && start.top()<=end.top()){
                start.pop();
            }
            if(end.size()-start.size()>=k){
                ele = end.top();
            }
            end.pop();
        }
        
        return ele;
    }
};
