class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here
        int n=arr.size(),i=0,j=0,sum=0,mini=INT_MAX;
                unordered_map<int,int> mp;

                while(j<n){
                    sum+=arr[j];
                    while(i<j and sum-arr[i]>x) sum-=arr[i++];
                    if(sum>x) mini=min(mini,j-i+1);
                    j++;
                }

                if(mini==INT_MAX) return 0;
                return mini;
    }
};
