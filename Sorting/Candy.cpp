class Solution {
    public:

int minCandy(int N, vector<int> &ratings) {
        vector<int>count(N, 1);
        for(int i=1; i<N; i++){
            if(ratings[i]>ratings[i-1]){
            count[i]= max(count[i], count[i-1]+1);
            }   
        }
        
        for(int i=N-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
            count[i] = max(count[i], count[i+1]+1);
            } 
        }
        
   return accumulate(begin(count), end(count), 0);
    }
};
