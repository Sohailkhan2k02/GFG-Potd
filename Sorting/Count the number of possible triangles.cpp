//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
          int n=arr.size();
        sort(arr.begin(),arr.end());
        int c=0; //count
        for(int high=n-1;high>=2;high--)
        {
            int low=0,i=high-1;
            while(low<i)
            {
                if(arr[low]+arr[i]>arr[high])
                {
                    c+=i-low;
                    i--;
                }
                else
                    low++;
            }
        }
        return c;
    }
};
