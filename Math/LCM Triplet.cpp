class Solution {
  public:
    int lcmTriplets(int n) {
        if(n<=2) return n;
        if(n%2==0 && n%3==0)
            return (n-2)*(n-1)*(n-3);
        else if(n%2==0)
            return n*(n-1)*(n-3);
        return n*(n-1)*(n-2);
    }
};
