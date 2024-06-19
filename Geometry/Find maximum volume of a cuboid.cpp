//T.C : O(1)
//S.C : O(1)
class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
        double ans =
            (pow((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12, 2) *
             ((perimeter / 4) -
              (2 * ((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12))));

        return ans;
    }
};
