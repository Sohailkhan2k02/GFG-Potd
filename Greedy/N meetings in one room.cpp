//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>vc;
        for(int i=0; i<n; i++){
            vc.push_back({start[i],end[i]});
        }
        auto lamda=[&](pair<int,int>a, pair<int,int>b){
            return a.second<b.second;
        };
        
        sort(vc.begin(),vc.end(),lamda);
        int cnt=0,prev=-1;
        for(auto i:vc){
            if(i.first>prev){
                cnt++;
                prev=i.second;
            }
        }
        
        return cnt;
    }
};
