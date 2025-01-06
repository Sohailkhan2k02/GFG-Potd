//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
          vector<int>ans;
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        while(i<j)
        {
            if(ans.size()==0)
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
            
            else if(arr[i]+arr[j]<=target)
            {
                if(abs(target-(arr[i]+arr[j]))==abs(target-(ans[0]+ans[1])))
                {
                    if(abs(arr[j]-arr[i])>abs(ans[0]-ans[1]))
                    {
                        ans[0]=arr[i];
                        ans[1]=arr[j];
                    }
                }
                
                else if(abs(target-(arr[i]+arr[j]))<abs(target-(ans[0]+ans[1])))
                {
                    ans[0]=arr[i];
                    ans[1]=arr[j];
                }
                
                i++;
            }
            
            else
            {
                if(abs(target-(arr[i]+arr[j]))==abs(target-(ans[0]+ans[1])))
                {
                    if(abs(arr[j]-arr[i])>abs(ans[0]-ans[1]))
                    {
                        ans[0]=arr[i];
                        ans[1]=arr[j];
                    }
                }
                
                else if(abs(target-(arr[i]+arr[j]))<abs(target-(ans[0]+ans[1])))
                {
                    ans[0]=arr[i];
                    ans[1]=arr[j];
                }
                
                j--;
                
            }
            
            
        }
        
        return ans;
    }
};
