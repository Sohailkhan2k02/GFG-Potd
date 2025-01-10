//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int i = 0;
        int j = 0;
        unordered_map<int,int>mpp;
        vector<int>ans;
        while(j < arr.size())
        {
            mpp[arr[j]]++;
            if(j-i+1 == k)
            {
                ans.push_back(mpp.size());
            }
            else if(j-i+1 > k)
            {
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0)
                {
                    mpp.erase(arr[i]);
                }
                i++;
                ans.push_back(mpp.size());
            }
            j++;
        }
        return ans;
    }
};
