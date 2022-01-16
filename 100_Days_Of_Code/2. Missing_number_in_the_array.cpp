/*Day 2 Dsa full  solution

Ques 2> Missing Number in an array

Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

// { Driver Code Starts
// Initial template for C++ */

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int sum = (n+1)*(n)/2;
      int s = 0;
      for(int i = 0; i<n-1; i++)
      {
          
          s = s + array[i];
          
      }
      
      if(s != sum)
      {
          return sum - s;
      }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends
