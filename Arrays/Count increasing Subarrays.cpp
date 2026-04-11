class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int i=1;
        int j=0;
        int ans=0;
        while(i<arr.size())
        {
            if(arr[i]>arr[i-1])
            {
                if(i-j+1>=2)
                {
                    ans+=i-j;
                }
            }
            else
            {
                j=i;
            }
            i++;
        }
        return ans;
    }
};
