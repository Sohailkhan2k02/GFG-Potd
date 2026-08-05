class Solution {
  public:
    int fun(vector<int>& arr, int p){
        
        int n=arr.size();
        int temp = 0;
        int start = 0;
        int end = 0;
        int sum = arr[0];
        
        while(end<n){
            
            if(start>end){
                end=start;
                if(end<n)
                sum+=arr[end];
            }
            else if(sum<p){
                
                temp+=(end-start+1);
                end++;
                if(end<n)
                sum+=arr[end];
                
            }
            else{
                sum-=arr[start];
                start++;
            }
            
        }
        
       return temp;
        
    }
    
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int a = fun(arr,l); // find subarray less then l;
       int b = fun(arr,r+1);// find subarray less then r+1;
       return b-a;
        
    }
};
