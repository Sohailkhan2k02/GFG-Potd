class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ps(n,-1), ns(n,-1),pg(n,-1),ng(n,-1);
        stack<int> s;
        int maxtime = 0;
        int mintime = 0;
        
        // next greater.
        
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i] > arr[s.top()]){
                ng[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        // next smaller.
        while(!s.empty())s.pop();
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i] < arr[s.top()]){
                ns[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        // previous smaller 
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[i] <= arr[s.top()]){
                ps[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        // prevoius greater
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[i] >= arr[s.top()]){
                pg[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            
            // total subarray contain arr[i] as max;
            int leftsize =  i-pg[i]; 
            int rightsize = ng[i]-i;
            if(ng[i]==-1)rightsize = n-i;
            
            
            maxtime+=(arr[i]*leftsize*rightsize);
            
            // total subarray contain arr[i] as min;
            leftsize =  i-ps[i];
            rightsize = ns[i]-i;
            if(ns[i]==-1)rightsize = n-i;
            
            mintime+=(arr[i]*leftsize*rightsize);
        }
        
        return (maxtime-mintime);
        
    }
};
