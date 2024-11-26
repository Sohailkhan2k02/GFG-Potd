//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int f1(vector<int>&arr){
        int maxi=0,sum=0;
        for(auto i:arr){
            sum+=i;
            if(sum<0) sum=0;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
    int f2(vector<int>&arr){
        int mini=INT_MAX,sum=0;
        for(auto i:arr){
            sum+=i;
            if(sum>0) sum=0;
            mini=min(mini,sum);
        }
        return mini;
    }
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n=arr.size();
        int maxi=f1(arr);
        if(maxi<0) return maxi;
        int mnn=f2(arr);
        int t=accumulate(arr.begin(),arr.end(),0);
        int mini=t-mnn;
        return max(maxi,mini);
    }
};
