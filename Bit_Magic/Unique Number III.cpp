//T.C : O(31*n)
//S.C : O(1)
// User function Template for C++
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=0;
        for(int k=0; k<=31; k++){
            int temp=1<<k;
            int cntzero=0,cntone=0;
            for(int i=0; i<n; i++){
                if((arr[i]&temp)!=0){
                    cntone++;
                }
                else{
                    cntzero++;
                }
            }
                
            if((cntone%3)==1){
                    ans|=temp;
            }
        }
        return ans;
    }
};
