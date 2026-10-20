class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        // code here
        int i = 0;
                while(i<arr.size()){
                    int j = i;
                    while(j+1<arr.size() && (arr[j]+arr[j+1])%2 == 0){
                        j++;
                    }
                    sort(arr.begin()+i, arr.begin()+j+1, greater<int>());
                    i = j+1;
                }
                return arr;
    }
};
