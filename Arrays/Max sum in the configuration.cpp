//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        unsigned long long sum=0;
        for(int i=0;i<n;i++)sum+=a[i];
        unsigned long long currSum=0;
        for(int i=0;i<n;i++){
          long long a1=a[i];
          a1=a1*i;
          currSum+=(a1);  
        }
        unsigned long long maxi=currSum;
        for(int i=n-1;i>=0;i--){
            currSum+=sum;
            unsigned long long a1=a[i];
            unsigned long long prod=a1*n;
            currSum-=(prod);
            maxi=max(maxi,currSum);
        }
        return maxi;
    }
};
