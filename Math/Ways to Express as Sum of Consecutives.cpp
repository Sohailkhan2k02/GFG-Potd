class Solution {
  public:
    int getCount(int n) {
        // code here
        while (n % 2 == 0) {
            n /= 2;
        }

        int divisorCount = 0;

        for (int i = 1; 1LL * i * i <= n; i++) {
            if (n % i == 0) {
                if (1LL * i * i == n) {
                    divisorCount++;
                } else {
                    divisorCount += 2;
                }
            }
        }

        return divisorCount - 1;
    }
};
