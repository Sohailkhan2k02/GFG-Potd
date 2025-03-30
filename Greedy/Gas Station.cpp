//T.C : O(n)
//S.C : O(1)
/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size(),total=0;
       for(int i=0;i<n;i++){
           total+= gas[i] - cost[i];
       }
       
       if(total<0) return -1;
       
       int res=0;
       total=0;
      for(int i=0;i<n;i++){
          total+=gas[i] - cost[i];
          if(total<0) {res=i+1; total=0;} //means this index aint answer, prolly next one is
       }
       
        return res;
    }
};
