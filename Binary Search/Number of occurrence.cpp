//T.C : O(log(n)+O(log(n))
//S.C : O(1)
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int cnt=0;
        int l=0,h=n-1;
        int ind1=-1,ind2=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(arr[m]>=target){
                ind1=m;
                h=m-1;
            }
            else l=m+1;
        }
        
        l=0,h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(arr[m]<=target){
                ind2=m;
                l=m+1;
            }
            else h=m-1;
        }
        if(ind1==-1 || ind2==-1) return 0; 
        return ind2-ind1+1;
    }
};
