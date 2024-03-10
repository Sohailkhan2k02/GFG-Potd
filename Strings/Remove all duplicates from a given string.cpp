//T.C : O(n)
//S.C : O(n)
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    int n=str.size();
	    string ans="";
	    unordered_set<char>st;
	    for(int i=0; i<n; i++){
	        if(st.find(str[i])==st.end()){
	            ans+=str[i];
	        }
	        st.insert(str[i]);
	    }
	    return ans;
	}
};
