class Solution {
  public:
    vector<int> subsetsum(vector<int>& v)
  {
      int n,mask,i,sum,j;
      vector<int> sum_subset;
      n=v.size();
      for(i=0;i<(1<<n);i++)
      {   sum=0;
          mask=i;
          for(j=0;j<32;j++)
          {
              if(mask&(1<<j))sum+=v[j];
          }
          sum_subset.push_back(sum);
      }
      return sum_subset;
      
  }
  public:
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n,n1,n2,n3,n4,i,temp,ans=0;
        n=arr.size();
        n1=n/2;
        n2=n-n1;
        vector<int> v1,v2,sum_subset1,sum_subset2;
        for(i=0;i<n1;i++)
        {
            v1.push_back(arr[i]);
        }
        for(i=0;i<n2;i++)
        {
            v2.push_back(arr[i+n1]);
        }
        sum_subset1= subsetsum(v1);
        sum_subset2= subsetsum(v2);
        n3=sum_subset1.size();
        n4=sum_subset2.size();
        sort(sum_subset2.begin(),sum_subset2.end());
        for(i=0;i<n3;i++)
        {
            temp=k-sum_subset1[i];
            ans+=upper_bound(sum_subset2.begin(),sum_subset2.end(),temp)-lower_bound(sum_subset2.begin(),sum_subset2.end(),temp);
        }
        return ans;
    }
};
