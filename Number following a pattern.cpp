// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int> st;
        string ans = "";
        int n = 1;
        for(int i = 0; i < S.size(); i++) {
            char ch = S[i];
            if(ch == 'D')
                st.push(n++);
            else {
                st.push(n++);
                while(!st.empty()) {
                    char c = '0' + st.top();
                    ans += c;
                    st.pop();
                }
            }
        }
        st.push(n++);
        while(!st.empty()) {
            char ch = '0' + st.top();
            ans += ch;
            st.pop();
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
