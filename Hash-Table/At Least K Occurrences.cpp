class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int,int>mpp;
        for(int i=0; i<n; i++){
            mpp[a[i]]++;
            if(mpp[a[i]]==k) return a[i];
        }
        return -1;
        // priority_queue<pair<int,int>>pq;
        // for(auto i:mpp){
        //     pq.push({-i.second,i.first});
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }
        
        // int res=-1;
        
        // while(!pq.empty()){
        //     if(-pq.top().first>=k){
        //     res=pq.top().second;
        //     break;
        //     }
        //     pq.pop();
        // }
        // return res;
    }
};
