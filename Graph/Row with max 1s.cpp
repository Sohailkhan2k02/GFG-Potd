// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int n=arr.size(),m=arr[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[j][i]==1){
                    return j;
                    break;
                    
                }
            }
        } 
      
      return -1;
    }
};
