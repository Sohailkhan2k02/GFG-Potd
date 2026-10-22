class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        int n=s.size();
               int sum=0;
               int l=0;
               int r=n-1;
               while(l<r)
               {
                   if(s[l]=='?' && s[r]!='?')
                   {
                       s[l]=s[r];
                   }
                   else if(s[l]!='?' && s[r]=='?')
                   {
                       s[r]=s[l];
                   }
                   else if(s[l]!=s[r])
                   {
                       return -1;
                   }
                   l++;
                   r--;
               }
               char ch='?';
               for(int i=0;i<n;i++)
               {
                   if(s[i]=='?')
                   {
                       s[i]=ch;
                   }
                   else
                   {
                       ch=s[i];
                   }
               }
               ch='?';
               for(int i=n-1;i>=0;i--)
               {
                   if(s[i]=='?')
                   {
                       s[i]=ch;
                   }
                   else
                   {
                       ch=s[i];
                   }
               }
               for(int i=0;i<n-1;i++)
               {
                   sum=sum+abs(s[i]-s[i+1]);
               }
               return sum;

    }
};
