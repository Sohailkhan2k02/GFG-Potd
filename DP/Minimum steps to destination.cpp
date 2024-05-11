// T.C : O(d)
// S.C : O(1)
class Solution {
  public:
    int minSteps(int d) {
        // code here
        d=abs(d);
        int cnt=0,sum=0;
        while(sum<d){
            cnt++;
            sum+=cnt;
        }
        while((sum-d)%2!=0){
            cnt++;
            sum+=cnt;
        }
        return cnt;
    }
};
