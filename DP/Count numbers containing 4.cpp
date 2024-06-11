//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public: 
// A utility function to compute sum of digits in a
// given number x
bool contains(int x)
{
    while (x != 0)
    {
        if (x%10 == 4)
           return true;
        x   = x /10;
    }
    return false;
}
    int countNumberswith4(int n) {
        // code here
int count = 0;
 
    bool dp[n + 1]
        = { 0 }; // boolean dp array to store whether
                 // the number contains digit '4' or not
 
    for (int i = 1; i <= n; i++) {
        if (dp[i]) { // if dp[i] is true that means
                     // that number contains digit '4'
            count++;
            continue; // if it contains then no need to
                      // check again hence continue
        }
 
        if (contains(i)) { // check if i contains digit '4'
                           // or not
            count++;
            dp[i]
                = true; // if it contains then mark dp[i] as
                        // true so that it can used later
        }
    }
 
    return count;
    }
};
