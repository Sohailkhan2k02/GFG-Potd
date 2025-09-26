class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
          k = k%dq.size();
        if(type==1) k = dq.size() - k;
        
        for(int i = 0;i<k;i++){
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
    }
};
