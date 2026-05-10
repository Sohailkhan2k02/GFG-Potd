class Solution {
  public:
    static bool cmp(pair<int,int>& p1, pair<int,int>& p2){
        
        return abs(p1.first - p1.second) >
               abs(p2.first - p2.second);
    }
  
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        
        int n = a.size();
        
        vector<pair<int,int>> tasks;
        
        for(int i = 0; i < n; i++){
            tasks.push_back({a[i], b[i]});
        }
        
        sort(tasks.begin(), tasks.end(), cmp);
        
        int profit = 0;
        
        for(auto &task : tasks){
            
            int A = task.first;
            int B = task.second;
            
            if((A >= B && x > 0) || y == 0){
                
                profit += A;
                x--;
            }
            else{
                
                profit += B;
                y--;
            }
        }
        
        return profit;
        
    }
};
