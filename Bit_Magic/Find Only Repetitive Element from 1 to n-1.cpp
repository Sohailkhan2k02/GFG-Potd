//T.C : O(n)
//S.C : O(1)
// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int total=0;
        for(int i=0;i<arr.size();i++)
        {
            total^=arr[i];
            if(i>=1)total^=i;
        }
        return total;
    }
};
