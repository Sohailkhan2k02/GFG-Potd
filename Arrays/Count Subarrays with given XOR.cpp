class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        map<int,int>mp;
        int prefix_xor=0,cnt=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefix_xor^=arr[i];
            if(mp.find(prefix_xor^k)!=mp.end()){
                cnt+=mp[prefix_xor^k];
            }
            mp[prefix_xor]++;
        }
        return cnt;
    }
};
