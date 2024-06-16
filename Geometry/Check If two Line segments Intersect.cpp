//T.C : O(1)
//S.C : O(1)
class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        double m1 = (double)(q1[1] - p1[1]) / (double)(q1[0] - p1[0]);
        double m2 = (double)(q2[1] - p2[1]) / (double)(q2[0] - p2[0]);
        if(m1 == m2){
            return "false";
        }
        bool chk211 = p2[1]-p1[1] - m1*(p2[0]-p1[0]) >0?true:false;
        bool chk212 = q2[1]-p1[1] - m1*(q2[0]-p1[0]) >0?true:false;
        bool chk121 = p1[1]-p2[1] - m2*(p1[0]-p2[0]) >0?true:false;
        bool chk122 = q1[1]-p2[1] - m2*(q1[0]-p2[0]) >0?true:false;
        if((chk211==true && chk212 == true) || (chk211==false && chk212 == false) || 
        (chk121 == true && chk122 == true) || (chk121 == false && chk122 == false)){
            return "false";
        }
        return "true";
    }
};
