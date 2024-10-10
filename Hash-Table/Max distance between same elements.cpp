//APPROACH -1 
//T.C: O(n+n+n)
//S.C : O(n+n)
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n=arr.size();
        unordered_map<int,int>m1,m2;
        for(int i=0; i<n; i++){
            if(m1.find(arr[i])==m1.end()){
                m1[arr[i]]=i;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(m2.find(arr[i])==m2.end()){
                m2[arr[i]]=i;
            }
        }
        
        int res=0;
        for(auto it:m1){
            int u=it.first;
            res=max(res,m2[u]-m1[u]);
        }
        return res;
        
    }
};

//APPROACH -2 
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n=arr.size();
        unordered_map<int,int>mpp;
        int res=0;
        for(int i=0; i<n; i++){
            if(mpp.find(arr[i])!=mpp.end()){
                res=max(res,i-mpp[arr[i]]);
            }
            else mpp[arr[i]]=i;
        }
        return res;
        
    }
};
