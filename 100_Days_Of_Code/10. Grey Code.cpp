// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      int b2g(int n)
   {
       
       // Your code here
       if(n==0)
       return 0;
       int set = 31;
       while((n>>set)==0)
       {
           set--;
       }
       int res = 1<<set;
       
       while(set>0)
       {
           int temp = (n>>set)&1;
           set--;
           temp = temp^((n>>set)&1);
           res = res|(temp<<set);
       }
       return res;
       
   }
   vector<string> graycode(int n)
   {
       //code here
       string ans ="";
       for(int i=0;i<n;i++)
       {
           ans+="0";
       }
       vector<string> res((1<<n),ans);
       for(int i=1;i<(1<<n);i++)
       {
           int temp = b2g(i);
           int shift=0;
           while(temp)
           {
               if(temp&1)
               {
                   res[i][n-1-shift]='1';
               }
               shift++;
               temp=temp>>1;
           }
       }
       
       return res;
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends