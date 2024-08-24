class Solution{
public:
long long countPairs(vector<int> &arr, vector<int> &brr) {
    long long ans = 0;

    sort(brr.begin(), brr.end());

    for (int x : arr) {
        if (x == 1) {
            continue;
        } else if (x == 2) {
            ans += upper_bound(brr.begin(), brr.end(), 1) - brr.begin();
            ans += brr.end() - lower_bound(brr.begin(), brr.end(), 5);
        } else {
            ans += brr.end() - lower_bound(brr.begin(), brr.end(), x + 1);
            ans += upper_bound(brr.begin(), brr.end(), 1) - lower_bound(brr.begin(), brr.end(), 1);
        }

        if (x == 3) {
            ans += upper_bound(brr.begin(), brr.end(), 2) - lower_bound(brr.begin(), brr.end(), 2);
        }
    }

    return ans;
}
};
