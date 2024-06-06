// Time complexity - O(max(r[i]))
// Space complexity- O(max(r[i]))
class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        int size=0;
        for(int i=0;i<n;i++)
        size=max(size,r[i]);
        
        int v[size+2]={0};
        for(int i=0;i<n;i++)
        {
            v[l[i]]++;
            v[r[i]+1]--;
        }
        
        int ans=-1;
        int freq=0;
        for(int i=1;i<=size;i++)
        {
            v[i]+=v[i-1];
            if(v[i])
            {
                if(v[i]>freq)
                {
                    freq=v[i];
                    ans=i;
                }
            }
        }
        return ans;
    }
};
