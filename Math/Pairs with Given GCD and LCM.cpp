class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        int n = 0, result = 0;
		if (y%x != 0)return 0;
		
		n = y/x;
		if (n == 1)return 1;
		for (int i = 1; i <= sqrt(n); ++i) {
			if (n%i == 0) {
				int j = n/i;
				if (i != j && gcd(i*x, j*x)
					 == x)result += 2;
			}
		}
		return result;
    }
};
