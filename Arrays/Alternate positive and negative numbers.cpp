//T.C : O(n)
//S.C : O(n)
class Solution {
  public:

    void rearrange(vector<int> &arr) {
    vector<int> pos, neg;
    int n = arr.size();
    

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        } else {
            neg.push_back(arr[i]);
        }
    }

    int i = 0, p = 0, ne = 0;
    

    while (p < pos.size() && ne < neg.size()) {
        arr[i++] = pos[p++];
        arr[i++] = neg[ne++];
    }

    while (p < pos.size()) {
        arr[i++] = pos[p++];
    }

    while (ne < neg.size()) {
        arr[i++] = neg[ne++];
    }
}

};
