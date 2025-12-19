class Solution {
  public:
    int findMoves(vector<int>& c, vector<int>& p) {
        // code here
        sort(c.begin(), c.end());
        sort(p.begin(), p.end());
        int sum=0;
        for(int i=0;i<c.size();i++)
        {
            sum+=abs(c[i]-p[i]);
        }
        return sum;
    }
};
