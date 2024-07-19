//T.C : O(n*logn)
//S.C : O(n)
class Solution{
public:	
     void merge(int start, int end, vector<pair<int, int>> &arr, vector<int>& count) {
        if(start < end && end - start > 1) {   
            int mid = start + (end - start) / 2;
            merge(start, mid, arr, count);
            merge(mid, end, arr, count);
            
            vector< pair<int, int>> ans;
            int i = start, j = mid;

            int inversions = 0;
            while(i < mid && j < end) {
                if(arr[i].first <= arr[j].first) {
                    ans.push_back(arr[i]);
                    count[arr[i].second] += inversions;
                    i++;
                }
                else {
                    ans.push_back(arr[j]);
                    inversions++;
                    j++;
                }
            }

            while(i < mid) {
                ans.push_back(arr[i]);
                count[arr[i].second] += inversions;
                i++;
            }

            while(j < end) {
                ans.push_back(arr[j]);
                j++;
            }

            j=0;
            for(int i=start; i<end; i++) {
                arr[i] = ans[j];
                j++;
            }           
        }
    }
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector< pair<int, int>> nums;
        vector<int> count(n, 0);
        
        for(int i=0; i<n; i++) {
            nums.push_back({arr[i], i});
        }
        
        merge(0,n,nums,count);
        return count;
	}
};
