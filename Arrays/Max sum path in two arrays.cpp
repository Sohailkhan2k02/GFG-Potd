//T.C : O(M+N)
//S.C : O(1)
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int n=arr1.size(),m=arr2.size();
        using ll=long long;
        ll s1=0,s2=0,res=0,i=0,j=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]) s1+=arr1[i++];
            else if(arr1[i]>arr2[j]) s2+=arr2[j++];
            else{
                res+=max(s1,s2)+arr1[i];
                s1=0,s2=0,i++,j++;
            }
        }
        while(i<n) s1+=arr1[i++];
        while(j<m) s2+=arr2[j++];
        res+=max(s1,s2);
        return res;
    }
};
