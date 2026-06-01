// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        // const int m=1e9+7;
        // int n=arr.size();
        // sort(arr.begin(),arr.end());
        // long long int neg=0,pos=0,maxi=1;
        // for(int i=0; i<n; i++){
        //     if(arr[i]<0) neg++;
        //     else if(arr[i]>0) pos++;
        // }
        // if(pos==0 && neg<=1){
        //     if(neg==n){
        //         maxi=arr[0];
        //     }
        //     else{
        //         maxi=0;
        //     }
        // }
        // else{
        //     for(int i=0; i<neg-(neg%2); i++){
        //         maxi=(maxi*arr[i])%m;
        //     }
        //     for(int i=0; i<pos; i++){
        //         maxi=(maxi*arr[n-i-1])%m;
        //     }
        // }
        // return maxi;
        
         long ans = 1;
        int mx = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=0){
                ans = (ans*arr[i])%1000000007;
            }
            
            if(arr[i]<0 && mx<arr[i]){
                mx = arr[i];
            }
        }
        
        if(ans<0) return ans/mx;
        return ans;
    }
};
