class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        int count[10001] = {0};
int count1[10001] = {0};
for (int i = 0; i<arr.size(); i++) {
int a = arr[i][0];
int b = arr[i][1];
count[a - 1]++;
count1[b - 1]++;
}
int maxi = 0;
int count2[10001] = {0};
for (int i = 0; i<n; i++) {
if (count[i] > 0) {
memset(count2, 0, sizeof(count2));
continue;
}
int sum = 0;
for (int j = 0; j<m; j++) {
if (count1[j] > 0) {
maxi = max(maxi, sum + count2[j]);
count2[j] = sum + count2[j];
sum = 0;
}
else {
sum++;
maxi = max(maxi, sum + count2[j]);
        count2[j] = sum + count2[j];
}
}
}
return maxi;
    }
};
