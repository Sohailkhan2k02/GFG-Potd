class Solution {
  public:
    virtual int minOperations(vector<int>& arr) {
      int steps=0;
      priority_queue<double> pq;
      
      double sum = 0;
      for(auto z: arr){
          sum += z;
          pq.push(z);
      }
      
      double reqSum = sum/2.0;
      
      while(sum > reqSum){
          steps++;
          double temp = ((pq.top())/2.0);
          pq.pop();
          sum -= temp;
          pq.push(temp);
      }
      
      return steps;
    }
};
