class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>temp(n,-1);
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=-1)
            {
                int idx=max(0,i-arr[i]);
                temp[idx]=max(temp[idx],i+arr[i]);
            }
        }
        int ans=0;
        int curr=-1;
        int mx=-1;
        int i=0;
        while(i<n)
        {
            mx=max(mx,temp[i]);
            if(curr<i)
            {
                if(mx<i)
                {
                    return -1;
                }
                else{
                    curr=mx;
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }
};
