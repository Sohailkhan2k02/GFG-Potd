class Solution {
  public:
   int countConsec(int n) {
        return pow(2, n) - countWithNoPair(n);
    }
    
    int countWithNoPair(int n){
        return travel(1, n, true) + travel(1, n, false);
    }
    
    int travel(int i, int n, bool prev){
        if(i == n){
            return 1;
        }
        if(prev){
            return travel(i + 1, n, false); 
        }else{
            return travel(i + 1, n, true) + travel(i + 1, n, false);
        }
    }
};
