class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>st;
        // st.push(arr[0]);
        for(int i=0;i<arr.size();i++)
        {
            if(st.size()==0)
            {
                st.push(arr[i]);
            }
            else
            {
                if(arr[i]==0)
                {
                    if(st.top()<0)
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(arr[i]);
                    }
                }
                else if(arr[i]*st.top()==0)
                {
                    if(arr[i]<0)
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(arr[i]);
                    }
                }
                else if(arr[i]*st.top()<0)
                {
                    st.pop();
                }
                else
                {
                    st.push(arr[i]);
                }
            }
        }
        
        int j=st.size()-1;
        vector<int>brr(j+1);
        while(st.size()>0)
        {
            brr[j--]=st.top();
            st.pop();
        }
        return brr;
    }
};
