class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n=arr.size();
        map<int,map<int,int>> mp;
        mp[0][arr[0]]=1;
        mp[0][-arr[0]]=1;
        
        for(int i=1;i<n;i++) {
            for(auto &I:mp[i-1]) {
                mp[i][arr[i]+I.first]+=mp[i-1][I.first];
                mp[i][-arr[i]+I.first]+=mp[i-1][I.first];
            }
        }
        return mp[n-1][target];
    }
};
