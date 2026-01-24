class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        deque<int>dq;
     for(int i=1;i<=n;i++){
         dq.push_back(i);
     }
     
     while(dq.size()!=1){
         int s = k-1;
         while(s--){
             int top = dq.front();
             dq.pop_front();
             dq.push_back(top);
         }
         dq.pop_front();
     }
     return dq.front();
    }
};
