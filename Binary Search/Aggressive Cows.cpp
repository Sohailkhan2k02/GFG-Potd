//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    bool f(int d, vector<int>&stalls, int k,int n){
        int cnt=1,prev=stalls[0];
        for(int i=1; i<n; i++){
            if((stalls[i]-prev)>=d){
                cnt++;
                prev=stalls[i];
            }
            if(cnt>=k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int l=1,h=stalls[n-1]-stalls[0];
        int res=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(f(m,stalls,k,n)){
                res=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return res;
    }
};
