class Solution {
  public:
    bool balancePan(int a, int b) {
        // code here
        if (a <= 0 or b < 0) return 0;
        if (a == 1) return 1;

        while (b) {
            int r = b % a;
            if (r == 0) b /= a;
            else if (r == 1) b = (b - 1) / a;
            else if (r == a - 1) b = (b + 1) / a;
            else return 0;
        }

        return 1;
    }
};
