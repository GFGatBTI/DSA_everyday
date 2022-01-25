// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node *getMiddile(Node *head)

  {

      Node *slow = head;

        Node *fast = head;

        Node *mid ;

        while(fast->next!=NULL && fast->next->next!=NULL)

        {

            slow = slow->next;

            fast = fast->next;

        }

        if(fast->next!=NULL)

         mid = slow->next;

         else

         mid = slow;

         slow->next = NULL;

         return mid;

  }

  

  // Merge two sorted List

  Node *merge(Node *head1 ,Node *head2)

  {

       Node *tail=NULL;

       Node *head = NULL;

      if(head1->data>head2->data)

      {

         head = tail = head2;

          head2 = head2->next;

      }

      else

      {

          head = tail = head1;

          head1 = head1->next;

      }

      while(head1!=NULL && head2!=NULL)

      {

          if(head1->data <= head2->data)

          {

              tail->next = head1;

              head1 = head1->next;

              tail = tail->next;

          }

          else 

          {

              tail->next = head2;

              head2 = head2->next;

              tail = tail->next;

          }

      }

      if(head1==NULL)

      tail->next = head2;

      else

      tail->next = head1;

     return head;

  }

  

    //Function to sort the given linked list using Merge Sort.

    Node* mergeSort(Node* head) {

        // your code here

        if(head==NULL ||  head->next == NULL)

            return head;

            

          Node *mid = getMiddile(head);

         Node *left = mergeSort(head);

        Node *right = mergeSort(mid);

       

        return  merge(left,right);;

    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends