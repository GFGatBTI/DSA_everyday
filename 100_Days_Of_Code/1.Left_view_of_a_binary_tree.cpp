/* Qn] Given a Binary Tree, print Left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 

The task is to complete the function leftView(), which accepts root of the tree as argument.

Topic: Queue
Complete question Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1 .

References from our side:
i] you must know the basics of the queue.
ii] Implementation hint: https://www.geeksforgeeks.org/print-left-view-binary-tree/ .

join us now, https://solo.to/gfgatbti to get displayed on our social media as geeks of the month, share the solution on LinkedIn and push your code to GitHub and tag us.*/ 

// #gfgatbti #gfgatbti_01



#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
        Node* left;
            Node* right;
            };
vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
        temp->data = val;
            temp->left = NULL;
                temp->right = NULL;
    return temp;
    }

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
        if(str.length() == 0 || str[0] == 'N')
                return NULL;
    // Creating vector of strings from input
        // string after spliting by space
            vector<string> ip;
    istringstream iss(str);
        for(string str; iss >> str; )
                ip.push_back(str);
    // for(string i:ip)
        //     cout<<i<<" ";
            // cout<<endl;
                // Create the root of the tree
                    Node* root = newNode(stoi(ip[0]));
    // Push the root to the queue
        queue<Node*> queue;
            queue.push(root);
    // Starting from the second element
        int i = 1;
            while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
                Node* currNode = queue.front();
                        queue.pop();
        // Get the current node's value from the string
                string currVal = ip[i];
        // If the left child is not null
                if(currVal != "N") {
            // Create the left child for the current node
                        currNode->left = newNode(stoi(currVal));
            // Push it to the queue
                        queue.push(currNode->left);
                                }
        // For the right child
                i++;
                        if(i >= ip.size())
                                    break;
                                            currVal = ip[i];
        // If the right child is not null
                if(currVal != "N") {
            // Create the right child for the current node
                        currNode->right = newNode(stoi(currVal));
            // Push it to the queue
                        queue.push(currNode->right);
                                }
                                        i++;
                                            }
    return root;
    }

int main() {
    int t;
        scanf("%d ",&t);
            while(t--)
                {
                        string s;
                                getline(cin,s);
                                        Node* root = buildTree(s);
                                                vector<int> vec = leftView(root);
                                                        for(int x : vec)
                                                                cout<<x<<" ";
                                                                        cout << endl;
                                                                            }
                                                                                return 0;
                                                                                }




//Function to return a list containing elements of left view of the binary tree.

void printLeftV(Node* root , vector<int>& ans , int level){
   if(!root)return;
      if(ans.size() == level){
             ans.push_back(root->data);
                }
                   printLeftV(root->left,ans,level+1);
                      printLeftV(root->right,ans,level+1);
                      }
                      vector<int> leftView(Node *root)
                      {
                        // Your code here
                          vector<int> ans;
                            printLeftV(root,ans,0);
                              return ans;
                              }
