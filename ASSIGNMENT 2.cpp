//ABHIJEET CHANDRA 
//21105116
//ECE


#include<bits/stdc++.h>
using namespace std;
 
 struct node
 {
    int data;
    node * next;
 };


class circular_linked_list
{
    node* head=NULL;// will point to the first element 
    node* last = NULL; // will point to the last element
   public:
    void insert( int data)
    {  node * temp = new node();
     temp->data= data;
        if(head==NULL)
        {
            head= temp;
            last= temp;
            last->next= head;
        }
        else{
        last->next= temp;
         last= temp;
         temp->next= head;
        }
    }
    void display()
    {   
    
         node * temp= head;
        cout<<"Head-->";
         while(temp->next!= head)
         { 
           
             cout<<temp->data<<"-->";
              temp= temp->next;
         }
          
             cout<<temp->data<<"-->Head";

    }

};
 
int main()
{ circular_linked_list a;
 a.insert(5);
 a.insert(10);
 a.insert(15);
 a.display();

    return 0;
}

// Q2. 

//  Practical applications of circular linked list:
//  1. It is also used by the Operating system to share time for different users, generally uses a Round-Robin time-sharing mechanism.
//  2. Undo functionality in Photoshop or Word
//  3. Circular linked lists are used in Round Robin Scheduling
//  4. Circular linked list used Most recent list (MRU LIST).