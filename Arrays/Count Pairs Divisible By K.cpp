class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int curr=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            arr[i]=(arr[i]%k);
            curr+=mp[(k-arr[i])%k];
            mp[arr[i]]++;
        }
        return curr;
    }
};
