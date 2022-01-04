// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decode(string& s, int l, int r) {
        int times = 0;
        string ans = "";
        stack<char> st;
        for(int i = l; i <= r; i++) {
            if(isdigit(s[i])) times = times * 10 +  (s[i] - '0');
            else if(s[i] == '[') {
                if(times == 0) times = 1;
                int j = i + 1;
                while(s[j] != ']' || !st.empty()) {
                    if(s[j] == ']') st.pop();
                    else if(s[j] == '[') st.push('[');
                    j++;
                }
                string rec = decode(s, i + 1, j - 1);
                i = j;
                while(times != 0) {
                    ans = ans + rec;
                    times--;
                }
            } else ans = ans + s[i];
        }
        return ans;
    }
    string decodedString(string s){
        // code here
        int l = 0, r = s.size() - 1;
        return decode(s, l, r);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
