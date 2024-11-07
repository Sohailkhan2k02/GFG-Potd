//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        vector<int>res;
        int n=arr.size();
        int curr=0;
        int sum=0;
        for(auto i:arr){
            sum+=i;
        }
        if(sum%3) return {-1,-1};
        for(int i=0; i<n; i++){
            curr+=arr[i];
            if(curr==sum/3){
                curr=0;
                res.push_back(i);
            }
        }
        
        if(curr) return {-1,-1};
        return res;
    }
};
