class Solution {
  public:
    int minTime(int N, int S1, int S2) {
        // code here
        int start = 1,end = N*min(S1,S2),mid = start + (end - start)/2;
               int ans = INT_MAX;
                while(start<=end){
                    int work1 = mid/S1;
                    int work2 = mid/S2;

                    if(work1+work2==N){
                        ans = min(ans,mid);
                        end = mid - 1;
                    }
                   else if(work1+work2>N){
                        end = mid - 1;
                        ans = min(ans,mid);
                    }
                    else{
                        start = mid + 1 ;
                    }
                    mid = start + (end - start)/2;

                }

                return ans;
    }
};
