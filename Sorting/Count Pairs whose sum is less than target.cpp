//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
         sort(arr.begin(),arr.end());
       int cnt=0,st=0,end=arr.size()-1;
       while(st<end){
           int sum=arr[st]+arr[end];
            if(sum>=target)end--;
            else{
                int len=end-st+1;
                if(len>1){
                    len--;
                    cnt+=len;
                }
                st++;
            }
       }
       return cnt;
    }
};
