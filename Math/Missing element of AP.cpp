//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n =arr.size();
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]-arr[i-1] > arr[i+1]-arr[i])
            {
               return arr[i]-(arr[i+1]-arr[i]);
            }
            else if(arr[i]-arr[i-1] < arr[i+1]-arr[i])
            {
                return arr[i]+(arr[i]-arr[i-1]);
            }
        }
        return arr[n-1]+(arr[n-1]-arr[n-2]);
    }
};

