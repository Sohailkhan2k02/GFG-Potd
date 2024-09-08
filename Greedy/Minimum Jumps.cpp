//T.C : O(n)
//S.C : O(1)
class Solution{
  public:
    int minJumps(vector<int>&arr){
        // Your code here
        int n=arr.size();
        if(n==0 || n==1) return 0;
        if(arr[0]==0) return -1;
        int c=0,cnt=0,maxi=-1;
        for(int i=0; i<n; i++){
            maxi=max(maxi,arr[i]+i);
            if(i==c){
                cnt++;
                c=maxi;
            }
            if(c>=n-1) return cnt;
        }
        return -1;
    }
};
