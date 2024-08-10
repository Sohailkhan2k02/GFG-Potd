//T.C: O(n*logn)
//S.C : O(n)
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> p;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            p.push_back({arr[i].profit,arr[i].dead});
            maxi=max(maxi,arr[i].dead);
        }
        
        sort(p.rbegin(),p.rend());
        vector<int> vis(maxi+1,0);
        
        set<int> s;
        for(int i=1;i<=maxi;i++)
        {
            s.insert(i);
        }
        
        int sum=0;
        int cnt=0;
        
        for(int i=0;i<p.size();i++)
        {
            if(s.empty())break;
            auto it=s.upper_bound(p[i].second);
            
            if((*it)==p[i].second)
            {
                sum+=p[i].first;
                cnt++;
                if(it==s.end())it--;
                s.erase(it);
                // return {*it,p[i].second};
            }else
            if(it!=s.begin())
            {
                it--;
                sum+=p[i].first;
                cnt++;
                s.erase(it);
            }
        }
        
        return {cnt,sum};
    } 
};
