//T.C : O(n)
//S.C : O(1)  
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=-1;
        int total=0;
        int left=0;
        for(auto it:arr)
        {
            total+=it;
        }
        for(int i=0;i<n;i++){
            int temp=arr[i];
            int right=total-left-temp;
            if(left==right)
            {
                ans=i;
                return ans;
            }
            left+=temp;
        }
        return ans;
    }
};
