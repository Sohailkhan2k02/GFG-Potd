class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int k  = q.size();
        queue<int>temp;
        k = k/2;
        for(int i=0;i<k;i++){
            temp.push(q.front());
            q.pop();
        }
        for(int i=0;i<k ; i++){
            q.push(temp.front());
            q.push(q.front());
            q.pop();
            temp.pop();
        }
        return;
    }
};
