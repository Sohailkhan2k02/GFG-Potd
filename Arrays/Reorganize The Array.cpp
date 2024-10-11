//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        int n=arr.size();
        unordered_set<int>st;
        for(auto i:arr){
            if(i!=-1) st.insert(i);
        }
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            if(st.find(i)==st.end()){
                res[i]=-1;
            }
            else{
                res[i]=i;
            }
        }
        return res;
    }
};

//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    vector<int> rearrange(vector<int>& arr) {
        // Code here
        int n=arr.size();
        for(int i=0; i<n; i++){
            while(arr[i]!=arr[arr[i]] && arr[i]!=-1){
                swap(arr[i],arr[arr[i]]);
            }
        }
        return arr;
    }
};
