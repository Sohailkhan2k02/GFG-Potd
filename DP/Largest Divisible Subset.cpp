//T.C : O(n*n + nlogn)
//S.C : O(n)
class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        sort(arr.rbegin(),arr.rend());
       int n=arr.size();
       vector<int>lds(n,1);
       vector<int>hash(n,0);
       iota(hash.begin(),hash.end(),0);
       int len=1;
       int last_ind=0;
       
       for(int curr=0;curr<n;curr++){
           for(int prev=0;prev<curr;prev++){
               if(arr[prev]%arr[curr]==0&&lds[prev]+1>lds[curr]){
                   lds[curr]=1+lds[prev];
                   hash[curr]=prev;
               }
           }
           if(len<lds[curr]){
               len=lds[curr];
               last_ind=curr;
           }
       }
       vector<int>ans;
       while(hash[last_ind]!=last_ind){
           ans.push_back(arr[last_ind]);
           last_ind=hash[last_ind];
       }
       ans.push_back(arr[last_ind]);
       return ans;
        
    }
};
