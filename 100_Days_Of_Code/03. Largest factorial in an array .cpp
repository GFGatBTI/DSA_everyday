/*  Large Factorial:
You are given an array A of integers of length N. You need to calculate factorial of each number. The answer can be very large, so print it modulo 109 + 7.*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) {
         long long max = -1;
       
       for(int i=0; i<n; i++){
           if(a[i] > max) max = a[i];
       }
         vector<long long> maxFact(max+1);
       long long res=1;
       maxFact[0] = maxFact[1] = 1;
       
       for(long long i=2; i<maxFact.size(); i++){
           res=(res*i)%1000000007;
           maxFact[i]=res;
       }
       
       for(int i=0; i<n; i++){
           a[i]=maxFact[a[i]];
       }
       
       return a;
   }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
