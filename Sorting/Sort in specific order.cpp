class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i=0,j=n-1;
        while(i<j)
        {
            while(i<n and arr[i]%2)
                i++;
            while(j>=0 and arr[j]%2 == 0)
                j--;
            if(i>=j)
                break;
            swap(arr[i],arr[j]);
        }
        sort(arr.begin(),arr.begin()+i,greater<int>());
        sort(arr.begin()+i,arr.end());
    }
};
