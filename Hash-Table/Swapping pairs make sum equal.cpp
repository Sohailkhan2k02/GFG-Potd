//T.C : O(n)
//S.C : O(n)
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
         unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        int sum1=0;
        int sum2=0;
        for(int i =0;i<n;i++){
            m1[a[i]]++;
            sum1+=a[i];
        }
        for(int i =0;i<m;i++){
            m2[b[i]]++;
            sum2+=b[i];
        }
        
        
        for(auto it:m1){
            int firstSum=sum1-it.first;
            int secondSum=sum2+it.first;
            if(firstSum>secondSum) continue;
            int diff=secondSum-firstSum;
            if(diff%2) continue;
            int req=diff/2;
            
            if(m2.find(req)!=m2.end()) return 1;
        }
        return -1;
    }
};
