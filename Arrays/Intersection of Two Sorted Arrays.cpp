class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        while(i<n && j<m){
            if(a[i]==b[j]){
                if (ans.size()==0){
                    ans.push_back(a[i]);
                }
                if (ans.size()!=0 && ans.back()!=a[i]){
                    ans.push_back(a[i]);
                }
                i++,j++;
            }
            else if (a[i]>b[j]){
                j++;
            }
            else if (b[j]>a[i]){
                i++;
            }
        }
        return ans;
    }
};
