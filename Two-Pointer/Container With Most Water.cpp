//T.C : O(n)
//S.C : O(1)
class Solution {

  public:
    int maxWater(vector<int> &A) {
        // code here
        int len=A.size();
        long long ans = 0;
    long long temp = 0;
    
    int i = 0, j = len - 1;
    
    while(i < j){
        long long h = min(A[i], A[j]);
        long long b = j - i;
        
        temp = h * b;
        ans = max(ans, temp);
        
        if(A[i] > A[j])
            --j;
        else
            ++i;
    }
    
    return ans;
    }
};
