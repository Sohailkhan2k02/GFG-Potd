class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n=seats.size();
        for(int i=1; i<n; i++){
            if(seats[i]==1 && seats[i-1]==1) return 0;
        }
        if(k==1 && n==1){
            return seats[0]==0?1:0;
        } 

        int cnt=0;
        for(int i=0; i<n; i++){
            if(i==0 && seats[i]==0){
                if(i+1<n && seats[i+1]==0){
                    seats[i]=1;
                    cnt++;
                }
            }else if(i==n-1 && seats[i]==0){
                if(i-1>=0 && seats[i-1]==0){
                    seats[i]=1;
                    cnt++;
                }
            }else{
                if(seats[i-1]==0 && seats[i+1]==0 && seats[i]==0){
                    seats[i]=1;
                    cnt++;
                }
            }
        }

        if(cnt>=k) return true;
        return false;
    }
};
