class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        map<int, int> freq, end;

      for(int &x: arr){
          freq[x]++;
      }
      
      for(int &x: arr){
          if(freq[x] == 0)
            continue;
          
          freq[x]--;
          
          if(end[x-1]){
              end[x-1]--;
              end[x]++;
          }
          else{
              //validate
              for(int i=1;i<k;i++){
                  if(freq[x+i] == 0)
                    return false;
              }
              
              for(int i=1;i<k;i++)
                freq[x+i]--;
              
              end[x+k-1]++;   
          }
          
      }
      
      return true;
    }
};
