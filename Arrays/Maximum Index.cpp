// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        int i = 0, j = n - 1;
        int res = 0;
        while (i <= j) {
            if (a[i] <= a[j]) {
                res = max(res, j - i);
                i++;
                j = n - 1;
            } else {
                j--;
            }
        }
        return res;
    }
};
