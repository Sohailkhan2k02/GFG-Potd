class Solution {
    private:
     vector<int> getPrevSmall(vector<int> &arr){
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        for(int i=0; i<arr.size(); i++){
            int element= arr[i];
            while(!st.empty() and arr[st.top()]>=element){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]= st.top();
            }
            st.push(i);
        }
        return ans;
        
    }
    vector<int> getNextSmall(vector<int> &arr){
        stack<int> st;
        vector<int> ans(arr.size(), arr.size());
        for(int i=arr.size(); i>=0; i--){
            int element= arr[i];
            while(!st.empty() and arr[st.top()]>= element){
                st.pop();
            }
            if(!st.empty()){
                ans[i]= st.top();
            }
            st.push(i);
        }
        return ans;
    }
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
         vector<int> prevSmall= getPrevSmall(arr);
         vector<int> nextSmall= getNextSmall(arr);
         //We havee have two arrus in thhe 
         vector<int> answer(arr.size(), 0);
        for(int i=0; i<arr.size(); i++){
            int minWindow= nextSmall[i]- prevSmall[i] -1;
            answer[minWindow-1]= max(answer[minWindow-1], arr[i]);
        }
       
        for(int i= arr.size()-2; i>=0; i--){
            answer[i]= max(answer[i], answer[i+1]);
        }
        
         
        return answer;
    }
};
