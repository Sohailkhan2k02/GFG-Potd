//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int,int>> temp;
        for (int i=0;i<n;i++){
            temp.push_back({finish[i],start[i]});
        }
        sort(temp.begin(),temp.end());
        
        int ans = 0;
        vector<bool> vis(n,0);
        int last = -1;
        last = temp[0].first;
        for (int i=1;i<n;i++){
            if (temp[i].second>last){
                ans++;
                last = temp[i].first;
            }
        }
        return ans+1;
    }
};
