//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& s, vector<int>& e) {
        int c=0;
        vector<pair<int,int>>p;
        for(int i=0;i<s.size();i++)p.push_back({s[i],e[i]});
        sort(p.begin(),p.end());
        vector<int>l;
        for(int i=0;i<p.size();i++){
            l.push_back(p[i].first-c);
            c=p[i].second;
        }
        l.push_back(eventTime-c);
        int q=0,w=0,h=0,g=0;
        for(int i=0;i<l.size();i++){
          q+=l[i];g=max(g,q);
          if(w==k)q-=l[h],h++,w--;
          w++;
        }
        return g;
    }
};
