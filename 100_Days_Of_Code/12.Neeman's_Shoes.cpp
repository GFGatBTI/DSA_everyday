 // Question Link: https://practice.geeksforgeeks.org/problems/neemans-shoes/1#
//Material Link: https://www.geeksforgeeks.org/sum-of-shortest-distance-on-source-to-destination-and-back-having-at-least-a-common-vertex/
// Solution in C++
// Copy the code and paste into the code prompt.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    string exercise(int N, int M, vector<vector<int>> A, int src, int dest, int X){
        // code here
         map<pair<int,int>,int> mp;
        map<pair<int,int>,int> vis;
        vector<int> adj[N];
        for(int i= 0; i < A.size(); i ++){
            auto it = A[i];
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            mp[{it[0],it[1]}] = it[2]; mp[{it[1],it[0]}] = it[2];
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> >q;
        q.push({0,src});
        int res = 0;
        while(!q.empty()){
            auto it = q.top(); q.pop();
            if(it.second == dest){
                res = it.first;
                break; }
            int i = it.second;
            for(int j : adj[i]){
                if(vis.find({i,j}) == vis.end()){
                q.push({it.first + mp[{i,j}],j});vis[{i,j}] = 1;vis[{j,i}] = 1;}
                else{continue;}
            }
        }
        if(res <= X)
            return "Neeman's Cotton Classics";
        return "Neeman's Wool Joggers";
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M, src, dest, X;
        cin >> N >> M >> src >> dest >> X;
        vector<vector<int>> A(M, vector<int> (3, 0));
        for(int i = 0; i < M; i++){
            cin >> A[i][0] >> A[i][1] >> A[i][2];
        }
        Solution obj;
        cout << obj.exercise(N, M, A, src, dest, X) << "\n";
    }
}

