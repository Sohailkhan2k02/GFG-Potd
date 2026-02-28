//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int closest_diff = INT_MAX;
        int element1 = INT_MIN, element2 = INT_MIN;
        int i =0, sum =0;
        int j = m-1;
        
        while(i<n && j>=0){
            sum = arr[i] + brr[j];
            if(abs(sum-x) < closest_diff){
                closest_diff = abs(sum-x);
                element1 = arr[i];
                element2 = brr[j];
            }
            
            else if(sum<x) i++;
            else j--;
    }
    vector<int> ans;
    ans.push_back(element1);
    ans.push_back(element2);
    
    return ans;
    }
};
