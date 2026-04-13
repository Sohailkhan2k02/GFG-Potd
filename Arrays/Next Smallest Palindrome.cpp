class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();
       vector<int> res = num;

        // Step 1: Check if all digits are 9
        bool all9 = true;
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {
                all9 = false;
                break;
            }
        }

        // If all 9 → answer is 1 0 0 ... 0 1
        if (all9) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            ans[n] = 1;
            return ans;
        }

        // Step 2: Mirror left to right
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;

        // Check if left side is smaller
        bool leftSmaller = false;
        while (i >= 0 && res[i] == res[j]) {
            i--;
            j++;
        }

        if (i < 0 || res[i] < res[j]) {
            leftSmaller = true;
        }

        // Mirror left to right
        i = mid - 1;
        j = (n % 2) ? mid + 1 : mid;
        while (i >= 0) {
            res[j] = res[i];
            i--;
            j++;
        }

        // Step 3: If left was smaller → increment middle
        if (leftSmaller) {
            int carry = 1;

            // Handle middle
            if (n % 2 == 1) {
                res[mid] += carry;
                carry = res[mid] / 10;
                res[mid] %= 10;
                i = mid - 1;
                j = mid + 1;
            } else {
                i = mid - 1;
                j = mid;
            }

            // Propagate carry and mirror
            while (i >= 0 && carry > 0) {
                res[i] += carry;
                carry = res[i] / 10;
                res[i] %= 10;

                res[j] = res[i];
                i--;
                j++;
            }
        }

        return res;
    }
};
