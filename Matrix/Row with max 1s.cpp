//T.C : O(n+m)
//S.C : O(1)
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int n=arr.size(),m=arr[0].size();
        int maxi=0,ind=-1;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<m; j++){
                if(arr[i][j]){
                    cnt++;
                }
            }
            if(maxi<cnt){
                maxi=cnt;
                ind=i;
            }
        }
        return ind;
    }
};
