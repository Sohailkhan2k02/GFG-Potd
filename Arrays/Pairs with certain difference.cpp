class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        if (n == 0) return 0;
        sort(arr.begin(), arr.end(), greater<int>());
        
        //unordered_set<int>st;
        long long sum=0;
        
        for(int i=1; i<n; i++){
            if(arr[i-1]-arr[i]<k){
                sum+=arr[i];
                sum+=arr[i-1];
                i++;
            }    
        }
        
        return sum;
    }
};
