//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        int maxi=-1,cnt=0;
        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                cnt++;
            }
            else cnt=0;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
