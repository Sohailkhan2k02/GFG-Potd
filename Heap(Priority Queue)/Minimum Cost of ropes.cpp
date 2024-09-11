//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        using ll=long long;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(auto i:arr) pq.push(i);
        ll sum=0;
        while(pq.size()>1){
            ll a=pq.top(); pq.pop();
            ll b=pq.top(); pq.pop();
            ll s=a+b;
            sum+=s;
            pq.push(s);
        }
        return sum;
    }
};
