//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        unordered_map<int,int>ump;
        ump[0]=1;
        int xCount=0,yCount=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                xCount++;
            }
            if(arr[i]==y)
            yCount++;
            if(ump.find(xCount-yCount)!=ump.end()){
                ans+=ump[xCount-yCount];
            }
            ump[xCount-yCount]++;
        }
        return ans;
    }
};
