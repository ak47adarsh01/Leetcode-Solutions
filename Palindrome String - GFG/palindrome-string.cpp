// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	 int isPalindrome(string S)
{
    int n=S.size();
    int c=0;
    for(int i=0,j=n-1;i<j;i++,j--){
        if(S[i]==S[j])
        c++;
    }
    if(c==n/2) return 1;
    else  return 0;
   }

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends