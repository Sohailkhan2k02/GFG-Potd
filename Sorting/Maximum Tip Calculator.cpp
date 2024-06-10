//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &a, vector<int> &b) {
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({a[i]-b[i],i});
        }
        sort(v.rbegin(),v.rend());
        long long ans =0;
        for(int i = 0;i<n;i++){
            if(v[i].first >= 0){
                if(x){
                    ans += a[v[i].second];
                    x--;
                }
                else{
                    ans += b[v[i].second];
                    y--;
                }
            }
            else if (v[i].first < 0){
                if(n-i <= y){
                    ans += b[v[i].second];
                    y--;
                }
                else{
                    ans += a[v[i].second];
                    x--;
                }
            }
        }
        return ans;
        
    }
};
