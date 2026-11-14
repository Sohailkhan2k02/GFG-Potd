class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here
        int sum1 = accumulate(begin(s1), end(s1), 0);
                int sum2 = accumulate(begin(s2), end(s2), 0);
                int sum3 = accumulate(begin(s3), end(s3), 0);

                int n1 = s1.size();
                int n2 = s2.size();
                int n3 = s3.size();

                int i = 0;
                int j = 0;
                int k = 0;

                // This Loop will run only max(n1, n2, n3) times
                while (true) {

                    if (sum1 == sum2 && sum2 == sum3) {
                        return sum1;
                    }

                    if (i == n1 && j == n2 && k == n3) {
                        break;
                    }


                    int maxSum = max({sum1, sum2, sum3});

                    if (sum1 == maxSum) {
                        sum1 -= s1[i];
                        if (i < n1) i++;
                    } else if (sum2 == maxSum) {
                        sum2 -= s2[j];
                        if (j < n2) j++;
                    } else {
                        sum3 -= s3[k];
                        if (k < n3) k++;
                    }
                }

                return 0;
    }
};
