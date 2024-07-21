//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
            // Write your code here
            sort(arr.begin(),arr.end());
            int n=arr.size();
            long long int prod=1;
            int mini=INT_MIN;
            for(int i=0;i<n;i++){
                if(arr[i]<0){
                    mini=max(arr[i],mini);
                }
                if(arr[i]!=0){
                    prod=prod*arr[i];
                    prod%=1000000007;
                }
            }
           if(prod<0){
               prod=prod/mini;
           }
           return prod;
        }
};
