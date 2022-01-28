/* 
Neeman's Shoes :

Due to the second wave of Gorona virus, Geekland imposed another lockdown and Geek has gained some wieght. Now Geek has decided to exercise.
There are N intersections in the city numbered from 0 to N-1 and M bidirectional roads each road connecting two intersections. 
All the intersections are connected to each-other through some set of roads, ith road connect intersections A[i][0] and A[i][1] and is of length A[i][2].
Every morning Geek will start at intersection src and will run/walk upto intersection dest. 
Geek only has one hour in the morning so he will choose to cover the shortest path from src to dest.
After planning his exercising schedule, Geek wants to buy the perfect shoes to walk/run in the morning. 
He goes to Neeman's Shoe factory which is the National Shoe factory of Geekland. 
Geek sees that there are two types of shoes "Neeman's Wool Joggers" and "Neeman's Cotton Classics", "Neeman's Wool Joggers" are good for running and "Neeman's Cotton Classics" are good for walking.
Geek is confused which shoes to buy, so he comes up with a strategy. 
If the distance he has to cover in the morning is less than or equal to X, then he will walk the distance, therefore he will buy "Neeman's Cotton Classics". If the distance is greater than X, he will buy "Neeman's Wool Joggers". 
Geek is too lazy to calculate the shortest distance between two intersections src and dest. 
Help him decide which shoes to buy.
*/

// Question Link: https://practice.geeksforgeeks.org/problems/neemans-shoes/1#
// Material Link: https://www.geeksforgeeks.org/sum-of-shortest-distance-on-source-to-destination-and-back-having-at-least-a-common-vertex/
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

