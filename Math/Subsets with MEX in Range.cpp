class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        // code here
        const long long MOD = 1000000007LL;
                int n = arr.size();

                vector<long long> freq(n + 2, 0);
                for (int x : arr) {
                    if (x <= n) freq[x]++;
                }

                vector<long long> pow2(n + 1, 1);
                for (int i = 1; i <= n; i++) {
                    pow2[i] = pow2[i - 1] * 2 % MOD;
                }


                vector<long long> suffix(n + 2, 0);
                for (int i = n; i >= 0; i--) {
                    suffix[i] = suffix[i + 1] + freq[i];
                }

                long long answer = 0;
                long long required = 1;
                bool possible = true;

                for (int k = 0; k <= r; k++) {
                    if (k > 0) {
                        if (freq[k - 1] == 0) {
                            possible = false;
                        } else {
                            required = required *
                                ((pow2[freq[k - 1]] - 1 + MOD) % MOD) % MOD;
                        }
                    }

                    if (k >= l && possible) {
                        long long unrestricted = pow2[suffix[k + 1]];
                        answer = (answer + required * unrestricted) % MOD;
                    }
                }

                return (int)answer;
    }
};
