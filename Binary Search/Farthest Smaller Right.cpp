class Solution {
  public:
    int helper(int tar,int i,vector<int>&temp){
      int res=-1;
      i++;
      int j=temp.size()-1;
      while(i<=j){
          int m=i+(j-i)/2;
          if(tar>temp[m]){
              res=m;
              i=m+1;
          }
          else{
              j=m-1;
          }
      }
      return res;
  }
    vector<int> farMin(vector<int>& arr) {
        // code here
        vector<int> temp(arr.size(), 0);
         int mini=INT_MAX-1;
         for(int i=arr.size()-1 ; i>=0 ; i--){
             mini=min(mini,arr[i]);
             temp[i]=mini;
         }
         vector<int>res(arr.size(), 0);
         for(int i=0 ; i<arr.size() ; i++){
             int val=helper(arr[i],i,temp);
             res[i]=val;
         }
         return res;
    }
};
