//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    void zigZag(int n, vector<int> &a) {
        // code here
        for(int i=0; i<n-1; i++){
            if(i&1){
                if(a[i]<a[i+1]){
                    swap(a[i],a[i+1]);
                }
            }
            else{
                if(a[i]>a[i+1]){
                    swap(a[i],a[i+1]);
                }
            }
        }
    }
};
