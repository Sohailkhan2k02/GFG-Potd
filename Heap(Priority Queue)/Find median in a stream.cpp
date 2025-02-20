//T.C : O(nlogn)
//S.C : O(logn)
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> result;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
            
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            if (maxHeap.size() == minHeap.size()) {
                result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                result.push_back((double)maxHeap.top());
            }
        }
        
        return result;
    }
};
