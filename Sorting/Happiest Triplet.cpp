class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        int n=a.size();
        int m=b.size();
        int l=c.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        vector<int>ans;
        int mini=INT_MAX;
        int i=0,j=0,k=0;
        while(i<n && j<m && k<l){
            if(a[i]>=b[j] && a[i]>=c[k]){
                if(b[j]>c[k]){
                    int diff=a[i]-c[k];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    k++;
                }
                else{
                    int diff=a[i]-b[j];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],c[k],b[j]};
                    }
                    j++;
                }
            }
            else if(b[j]>=a[i] && b[j]>=c[k]){
                if(a[i]>c[k]){
                    int diff=b[j]-c[k];
                    if(diff<mini){
                        mini=diff;
                        ans={b[j],a[i],c[k]};
                    }
                    k++;
                }
                else{
                    int diff=b[j]-a[i];
                    if(diff<mini){
                        mini=diff;
                        ans={b[j],c[k],a[i]};
                    }
                    i++;
                }
            }
            else{
                if(a[i]>b[j]){
                    int diff=c[k]-b[j];
                    if(diff<mini){
                        mini=diff;
                        ans={c[k],a[i],b[j]};
                    }
                    j++;
                }
                else{
                    int diff=c[k]-a[i];
                    if(diff<mini){
                        mini=diff;
                        ans={c[k],b[j],a[i]};
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};
