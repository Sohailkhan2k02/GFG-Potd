class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n%2==0){
            if(arr[n/2]-arr[n/2-1]>=k) 
            return (arr[n/2]+arr[n/2-1]+k)/2; 
        } 
        int s;
        if(n%2==0)s=n/2-1;
        else s=n/2;
        int mid=arr[s];
        int prev=arr[s];
        //store difference (arr[i]-arr[i-1]) from mid to the end of arr
        for(int i=s+1;i<arr.size();i++){
            int temp=arr[i];
            arr[i]=arr[i]-prev;
            prev=temp;
        }
        int i=s+1;
        int count=1;
        while(i<arr.size()&&k-(count*arr[i])>=0){
            mid+=arr[i];
            k=k-count*arr[i];
            i++;
            count++;
        }
        mid+=k/count;
        return mid;
    }
};
