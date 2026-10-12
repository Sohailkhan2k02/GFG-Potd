class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int result = 0;
				while (n != 0 && m != 0) {
					if (n <= m) {
						result += m/n;
						m %= n;
					} else {
						result += n/m;
						n %= m;
					}
				}
				return result;
			
    }
};
