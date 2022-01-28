/*  Find median in a stream:
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
   public:
   //Function to insert heap.
   priority_queue<int> maxH;
   priority_queue<int,vector<int>,greater<int>> minH;
   // int c=0;
   
   void insertHeap(int &x)
   {
       if(maxH.size()==0){
           maxH.push(x);
       }
       else if(x<maxH.top()){
           maxH.push(x);
       }
       else{
           minH.push(x);
       }
       // c++;
       balanceHeaps();
   }
   
   //Function to balance heaps.
   void balanceHeaps()
   {
       if(maxH.size()>minH.size() && (maxH.size()-minH.size() ) >1){
           int t=maxH.top();
           maxH.pop();
           minH.push(t);
       }
       else if(maxH.size()<minH.size() && (minH.size()-maxH.size() ) >1){
           int t=minH.top();
           minH.pop();
           maxH.push(t);
       }
   }
   
   //Function to return Median.
   double getMedian()
   {
       if(maxH.size()==minH.size()){
           double m=(maxH.top()+minH.top())/2.0;
           return m;
       }
       else{
           if(maxH.size()>minH.size()){
               return maxH.top();
           }
           else{
               return minH.top();
           }
       }
   }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
