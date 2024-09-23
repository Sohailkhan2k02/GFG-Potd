//T.C : O(n)
//S.C : O(1)
class Solution{
public:
     vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int miss=-1,rep=-1;
        for(int i=0; i<n; i++){
            int num=abs(arr[i]);
            if(arr[num-1]<0){
                rep=num;
            }
            else{
                arr[num-1]=-arr[num-1];
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i]>0){
                miss=i+1;
            }
        }
        return {rep,miss};
    }
};
