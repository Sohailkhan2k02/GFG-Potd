class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long s=0;
        for(int i =0;i<n;i++)s += arr[i];
         if( s%2==1)return 0;
         long long l =0;
          for(int i =0;i<n;i++){
               l+= arr[i];
               s-= arr[i];
               if( l==s) return 1;
               if(l>s) return 0;
          }
           return 0;
    }
};
