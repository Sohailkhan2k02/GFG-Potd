//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
         int n=arr.size();

        int left=0;

        int right=n-1;

        int count=0;

        while(left<right){

            int sum=arr[left]+arr[right];

            if(sum==target){

               count++; 

               int tempright=right-1;

               while(tempright>left &&  arr[left]+arr[tempright]==target){

                   count++;

                   tempright--;

               }

               left++;

            }

                 else if(sum>target){

                   right--;

               }

               else {

                   left++;

               }

            }

            return count;

        }
};
