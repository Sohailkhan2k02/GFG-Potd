//T.C : O(n*logk)
//S.C : O(1)
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        auto isValid = [](double maxDist, const vector<int>& positions, int maxStations) {
            int reqStations = 0;
            for (int i = 1; i < positions.size(); ++i) {
                double dst = positions[i] - positions[i - 1];
                reqStations += static_cast<int>(dst / maxDist);
            }
            return reqStations <= maxStations;
        };
        
        // binary search in answer's range
        double l = 0;
        double r = stations.back() - stations.front();
        double res = r;
        
        // difference r-l should be greater then epsilon
        while (r - l > 1e-6) {
            double m = (l + r) / 2.0;
            if (isValid(m, stations, k)) {
                r = m;
                res = m;
            } else {
                l = m;
            }
        }
        
        return res;
    }
};
