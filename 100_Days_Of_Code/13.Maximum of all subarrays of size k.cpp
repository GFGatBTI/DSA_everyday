 // Question Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
//Material Link: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
// Solution in C++
// Copy the code and paste into the code prompt.

// class Solution
// {
//   public:
//     //Function to find maximum of each subarray of size k.
//     vector <int> max_of_subarrays(int *arr, int n, int k)
//     {
//         // your code here
//         vector<int>v;
//         deque<int>q;
//        int i=0,j=0;
//        while(j<n)
//        {
//            while(q.size()>0 && arr[j]>q.back()){
//            q.pop_back();
//            }
           
//           q.push_back(arr[j]);
//           if(j-i+1<k) j++;
//           else if(j-i+1==k)
//           {
//               v.push_back(q.front());
//               if(q.front()==arr[i])
//               q.pop_front();
//               i++;j++;
              
//           }
           
           
//        }
//        return v;
//     }
// };


// OR




// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *v, int n, int k)
   {
        priority_queue<pair<int,int>>pq;
   vector<int>ans;
   pq.push(make_pair(1,1));
   int res=0;
   for(int i=0;i<k;i++){
       if(res<v[i]){
           pq.pop();
           res=v[i];
       }

         pq.push(make_pair(v[i],i));
   }
   ans.push_back(res);

   for(int i=k;i<n;i++){
         if(i-k<pq.top().second&&v[i]<pq.top().first){
           ans.push_back(pq.top().first);
         }
         else{
           while(i-k>=pq.top().second&&pq.empty()==false)
               pq.pop();
           if(i-k<pq.top().second&&v[i]<pq.top().first)
           ans.push_back(pq.top().first);
         else
           ans.push_back(v[i]);
         }
          pq.push(make_pair(v[i],i));
   }
   return ans;
   }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends