//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	bool static compare(string &s1, string &s2){
	    return s1+s2>s2+s1;
	}
	string printLargest(int n, vector<string> &a) {
	    // code here
	    string res="";
	    sort(a.begin(),a.end(),compare);
	    for(int i=0; i<n; i++){
	        res+=a[i];
	    }
	    return res;
	}
};
