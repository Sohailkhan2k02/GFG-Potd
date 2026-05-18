class Solution
{
    public:
        int f(int i){
            if(i==0) return 0;
            if(i==1) return 1;
            
            int u=f(i/2),v=f(i/3),w=f(i/4);
            return max(i,(u+v+w));
        }
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n+1,-1);
            return f(n);
        }
};
